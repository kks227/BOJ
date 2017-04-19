#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, int> Edge;

int uf[100];

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
	int N, W = 0;
	vector<Edge> edge;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			char c = getchar();
			if(c != '0'){
				int d = (c<='Z' ? c-'A'+27 : c-'a'+1);
				W += d;
				edge.push_back(Edge(d, i, j));
			}
		}
	}
	sort(edge.begin(), edge.end());

	fill(uf, uf+N, -1);
	int cnt = 0;
	for(auto &e: edge){
		int u, v, w;
		tie<int, int, int>(w, u, v) = e;
		if(uf_union(u, v)){
			cnt++;
			W -= w;
		}
	}
	printf("%d\n", cnt == N-1 ? W : -1);
}