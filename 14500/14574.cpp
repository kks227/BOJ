#include <cstdio>
#include <vector>
#include <tuple>
#include <set>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Edge;

struct UnionFind{
	int uf[1000];
	UnionFind(){ fill(uf, uf+1000, -1); }
	int f(int a){
		if(uf[a] < 0) return a;
		return uf[a] = f(uf[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		uf[b] = a;
		return true;
	}
};

int main(){
	int N, P[1000], C[1000];
	vector<Edge> edge;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d %d", P+i, C+i);
		for(int j=0; j<i; j++)
			edge.push_back(Edge((C[i]+C[j])/abs(P[i]-P[j]), i, j));
	}
	sort(edge.begin(), edge.end());

	UnionFind UF;
	int cnt = 0;
	set<int> adj[1000];
	long long result = 0;
	for(int i=edge.size()-1; ; i--){
		int a, b, c;
		tie(c, a, b) = edge[i];
		if(UF.u(a, b)){
			result += c;
			adj[a].insert(b);
			adj[b].insert(a);
			if(++cnt == N-1) break;
		}
	}
	printf("%lld\n", result);

	for(int k=0; k<N-1; k++){
		for(int i=0; i<N; i++){
			if(adj[i].size() == 1){
				int j = *adj[i].begin();
				printf("%d %d\n", j+1, i+1);
				adj[i].erase(j);
				adj[j].erase(i);
				break;
			}
		}
	}
}