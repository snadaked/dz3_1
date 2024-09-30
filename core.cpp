#include "ks.h"
using namespace std;
void Parser::split_input(const string line, string & sv, string & sw) const{
	stringstream str(line);			//make artifical stream
	str >> sv >> sw;			 	//and read from it
}

void Parser::read(){
	ifstream file(filename);
	file.seekg(0, std::ios::end);
	file.seekg(0, std::ios::beg);
	string line;
	getline(file, line);
	string sn, sk;
	split_input(line, sn, sk);
	size = stoi(sn);
	wmax = stod(sk);
	while (getline(file, line) and !file.eof()){
		string sv, sw;
		split_input(line, sv, sw);
		items.push_back({stod(sv), stod(sw)});
	}
	file.close();
}

vector<item> Parser::get_items() const{
	return items;
}

double Solver::get_profit(){
    sort(items.begin(), items.end(), cmp);
    queue<node> q;
    node u, v;
 
    u.level = -1;
    u.cost = u.w = 0;
    q.push(u);
	
	int n = items.size();
    double max_cost = 0.0;
    while (!q.empty())
    {
        // Dequeue a node
        u = q.front();
        q.pop();
 
        // If it is starting node, assign level 0
        if (u.level == -1)
            v.level = 0;
 
        if (u.level != n-1){
			//put next
			v.level = u.level+1;
			v.w = u.w + items[v.level].w;
			v.cost = u.cost + items[v.level].v;
			
			if (v.w <= max && v.cost > max_cost) max_cost = v.cost;
			v.bound = get_bound(v);
			if (v.bound > max_cost) q.push(v);
	 
			//same but without putting into knapsack
			v.w = u.w;
			v.cost = u.cost;
			v.bound = get_bound(v);
			
			if (v.bound > max_cost) q.push(v);
		}
    }
    return max_cost;
}

double Solver::get_bound(node u){
	sort(items.begin(), items.end(), cmp);
    if (u.w >= max) return 0;
 
    int cost = u.cost;
    int j = u.level+1;
    int w = u.w;
    int n = items.size();
 
    while ((j < n) && (w + items[j].w <= max)){
        w += items[j].w;
        cost += items[j].v;
        j++;
    }
    if (j < n) cost += (max - w)*items[j].v/items[j].w;
    return cost;
}

