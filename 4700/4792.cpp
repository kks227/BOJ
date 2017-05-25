#include <cstdio>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<char, int, int> Edge;

struct UnionFind{
	int p[1000];
	UnionFind(){ clear(); }
	void clear(){ fill(p, p+1000, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[b] = a;
		return true;
	}
};

int main(){
	while(1){
		int N, M, K;
		scanf("%d %d %d", &N, &M, &K);
		if(N == 0) break;

		vector<Edge> edge;
		for(int i=0; i<M; i++){
			char c;
			int f, t;
			scanf(" %c %d %d", &c, &f, &t);
			edge.push_back(Edge(c, f-1, t-1));
		}
		sort(edge.begin(), edge.end());
		int result[2] = {0};
		for(int i=0; i<2; i++){
			UnionFind UF;
			int cnt = 0;
			for(int j=0; ; j++){
				if(UF.u(get<1>(edge[j]), get<2>(edge[j]))){
					if(get<0>(edge[j]) == 'B') result[i]++;
					if(++cnt == N-1) break;
				}
			}
			if(i == 0) reverse(edge.begin(), edge.end());
		}
		printf("%d\n", result[1] <= K && K <= result[0]);
	}
}