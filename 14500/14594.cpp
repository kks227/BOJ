#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 101;

struct UnionFind{
	int p[MAX];
	UnionFind(int N){
		for(int i = 1; i <= N; ++i)
			p[i] = -i;
	}
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		if(a > b) swap(a, b);
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[a] = p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	UnionFind UF(N);
	int result = N;
	for(int i = 0; i < M; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		while(1){
			int L = UF.f(s), R = -UF.p[L];
			if(R >= e) break;
			--result;
			UF.u(L, R+1);
		}
	}
	printf("%d\n", result);
}