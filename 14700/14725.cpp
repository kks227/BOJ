#include <iostream>
#include <string>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

struct Cell{
	map<string, Cell*> next;
};

Cell *root = new Cell;

void dfs(Cell *curr, int depth = 0){
	for(auto &p: curr->next){
		cout << string(depth*2, '-') << p.first << endl;
		dfs(p.second, depth+1);
	}
}

int main(){
	int N;
	cin >> N;
	for(int i=0; i<N; i++){
		int K;
		cin >> K;
		Cell *curr = root;
		for(int j=0; j<K; j++){
			string str;
			cin >> str;
			auto iter = curr->next.find(str);
			if(iter == curr->next.end()) curr = curr->next[str] = new Cell;
			else curr = iter->second;
		}
	}
	dfs(root);
}