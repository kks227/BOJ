#include <iostream>
#include <queue>
#include <set>
using namespace std;

typedef set<int> intSet;

class gpNode{
public:
	gpNode():flag(false){}
	bool flag;
};

class Graph{
public:
	Graph():size(5){
		node = new gpNode[5];
		adj = new intSet[5];
	}
	Graph(int n):size(n){
		node = new gpNode[n];
		adj = new intSet[n];
	}
	~Graph(){
		delete[] node;
		delete[] adj;
	}

	int BFS(int start){
		int result = 0;
		queue<int> next;
		int qsize, current;
		next.push(start);
		while(!next.empty()){
			qsize = next.size();
			for(int i=0; i<qsize; i++){
				current = next.front();
				next.pop();
				if(node[current].flag) continue;
				node[current].flag = true;
				result++;
				intSet& curSet = adj[current];
				for(intSet::iterator iter=curSet.begin(); iter!=curSet.end(); iter++)
					next.push(*iter);
			}
		}
		return result-1;
	}
	void addEdge(int u, int v){
		adj[u].insert(v);
		adj[v].insert(u);
	}
private:
	int size;
	gpNode *node;
	intSet *adj;
};

int main(){

	int N, M;
	cin >> N >> M;
	Graph gp(N);
	int p, q;
	for(int i=0; i<M; i++){
		cin >> p >> q;
		gp.addEdge(p-1, q-1);
	}
	cout << gp.BFS(0) << endl;

	return 0;
}