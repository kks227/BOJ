#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int V = 100;
const int Q = 10;
typedef pair<int, int> P;

int main(){
	vector<P> adj[V];
	int E = 1050;
	for(int i = 1; i < V; ++i){
		adj[0].push_back(P(i, 2*(V-i)));
		adj[(i+1)%V].push_back(P(i, 1));
		E -= 2;
	}
	for(int i = 0; i < E; ++i)
		adj[0].push_back(P(1, 999999));
	printf("%d\n", V);
	for(int i = 0; i < V; ++i){
		printf("%d", adj[i].size());
		for(auto &p: adj[i])
			printf(" %d %d", p.first, p.second);
		puts("");
	}
	printf("%d\n", Q);
	for(int i = 0; i < 10; ++i)
		printf("%d %d\n", 0, 1);
}