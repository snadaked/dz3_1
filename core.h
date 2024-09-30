#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
struct item{
    double w;
    double v;
    item(double a = 0.0, double b = 0.0){
		v = a;
		w = b;
	}
	~item(){}
};

struct node{
    int level;
    double w, cost, bound;
};

using namespace std;
class Parser{
	int size;
	double wmax;
	vector<item> items;
	string filename;
	void split_input(const string line, string & sv, string & sw) const;
public:
	Parser(string fname = ""){
		size = 0;
		filename = fname;
	}
	~Parser(){}
	
	int get_size() const{return size; }
	int get_max() const{return wmax; }
	void read();
	vector<item> get_items() const;
	void show_items();
	
	Parser * operator= (Parser * p){
		for(auto & elem : p->get_items())
			items.push_back(elem);
		size = p->size;
		wmax = p->wmax;
		filename = p->filename;
		return this;
	}
};

class Solver{
	int max;
	Parser * parser;
	vector<item> items;
	struct{
		bool operator()(item a, item b) const{
			return (a.v)/(a.w)> (b.v)/(b.w);
		}
	}cmp;
public:
	Solver(){}
	Solver(Parser * p){
		parser = p;
		max = p->get_max();
		items = p->get_items();
	}
	~Solver(){}
	double get_profit();
	double get_bound(node u);
	Solver * operator= (Solver * s){
		//allocate memory
		Parser tmp(*(s->parser));
		parser = &tmp;
		return this;
	}
};
