#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie{
	string dname;
	vector<Trie*> next;
	Trie(): Trie(""){}
	Trie(string d): dname(d){}

	void insert(string &path, int pos){
		if(pos >= path.size()) return;
		int len = find(path.begin()+pos, path.end(), '\\') - (path.begin()+pos);
		string split = path.substr(pos, len);
		
		for(int i=0; i<next.size(); i++){
			if(next[i]->dname == split){
				next[i]->insert(path, pos+len+1);
				return;
			}
		}
		Trie *newNode = new Trie(split);
		next.push_back(newNode);
		newNode->insert(path, pos+len+1);
	}
	void print(int depth = -1){
		if(depth >= 0) cout << string(depth, ' ') << dname << endl;
		sort(next.begin(), next.end(), [](const Trie *A, const Trie *B){ return (A->dname < B->dname); });
		for(Trie *T: next) T->print(depth+1);
	}
};

int main(){
	int N;
	cin >> N;
	Trie *root = new Trie;
	for(int i=0; i<N; i++){
		string path;
		cin >> path;
		root->insert(path, 0);
	}
	root->print();
}