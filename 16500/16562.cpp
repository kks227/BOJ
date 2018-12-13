#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int INF = 1e9;

struct UnionFind{
	int p[MAX], minVal[MAX];
	UnionFind(){
		fill(p, p+MAX, -1);
		fill(minVal, minVal+MAX, INF);
	}
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		minVal[a] = min(minVal[b], minVal[a]);
		p[b] = a;
		return true;
	}
};

int main(){
	int N, M, K;
	UnionFind UF;
	scanf("%d %d %d", &N, &M, &K);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		UF.minVal[i] = val;
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		UF.u(u-1, v-1);
	}

	long long result = 0;
	bool visited[MAX] = {false,};
	for(int i = 0; i < N; ++i){
		int u = UF.f(i);
		if(!visited[u]){
			visited[u] = true;
			result += UF.minVal[u];
		}
	}
	if(result <= K) printf("%lld\n", result);
	else puts("Oh no");
}