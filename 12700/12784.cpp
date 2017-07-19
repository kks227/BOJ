#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
const int INF = 1e9;
typedef pair<int, int> P;

int N;
bool visited[1000];
vector<P> adj[1000];

int dynamite(int curr){
	int result = 0;
	visited[curr] = true;
	bool leaf = true;
	for(auto &p: adj[curr]){
		int next = p.first, d = p.second;
		if(!visited[next]){
			result += min(dynamite(next), d);
			leaf = false;
		}
	}
	return leaf ? INF : result;
}

int main(){
	int T, dummy;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &dummy);
		if(N == 1){
			puts("0");
			continue;
		}
		
		for(int i=0; i<N-1; i++){
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			adj[u].push_back(P(v, w));
			adj[v].push_back(P(u, w));
		}
		printf("%d\n", dynamite(0));

		fill(visited, visited+N, false);
		for(int i=0; i<N; i++)
			adj[i].clear();
	}
}