#include <cstdio>
#include <vector>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
typedef tuple<int, int, int> Edge;

int uf[200];

int uf_find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = uf_find(uf[a]);
}

bool uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a == b) return false;
	uf[b] = a;
	return true;
}



int main(){
	int N, cnt = 0, C = 0, M;
	vector<Edge> edge;
	scanf("%d", &N);
	fill(uf, uf+N, -1);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int val;
			scanf("%d", &val);
			if(i <= j) continue;

			if(val < 0){
				C -= val;
				if(uf_union(i, j)) cnt++;
			}
			else edge.push_back(Edge(val, i, j));
		}
	}
	M = N-1-cnt;
	sort(edge.begin(), edge.end());

	vector<P> result;
	for(int i=0; cnt<N-1; i++){
		int u, v, w;
		tie(w, u, v) = edge[i];
		if(uf_union(u, v)){
			C += w;
			result.push_back(P(u+1, v+1));
			cnt++;
		}
	}
	printf("%d %d\n", C, M);
	for(auto &p: result)
		printf("%d %d\n", p.first, p.second);
}