#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
typedef tuple<double, int, int> Edge;

int uf[1002];

int find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = find(uf[a]);
}

bool merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return false;
	if(uf[a] < uf[b]){
		uf[a] += uf[b];
		uf[b] = a;
	}
	else{
		uf[b] += uf[a];
		uf[a] = b;
	}
	return true;
}

inline double dist(int x1, int y1, int x2, int y2){
	return sqrt(1LL*(x1-x2)*(x1-x2) + 1LL*(y1-y2)*(y1-y2));
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int W, N, x[1000], y[1000], r[1000];
		scanf("%d %d", &W, &N);
		for(int i=0; i<N; i++)
			scanf("%d %d %d", x+i, y+i, r+i);
		vector<Edge> edge;
		edge.push_back(Edge(W, N, N+1));
		for(int i=0; i<N; i++){
			edge.push_back(Edge(max(0, x[i]-r[i]), i, N));
			edge.push_back(Edge(max(0, W-x[i]-r[i]), i, N+1));
			for(int j=0; j<i; j++)
				edge.push_back(Edge(max(0.0, dist(x[i], y[i], x[j], y[j])-r[i]-r[j]), j, i));
		}

		memset(uf, -1, sizeof(uf));
		sort(edge.begin(), edge.end());
		for(int i=0; i<edge.size(); i++){
			int a = get<1>(edge[i]), b = get<2>(edge[i]);
			double d = get<0>(edge[i]);
			if(merge(a, b)){
				if(find(N) == find(N+1)){
					if(d == 0) puts("0");
					else printf("%.6lf\n", d/2);
					break;
				}
			}
		}
	}
}