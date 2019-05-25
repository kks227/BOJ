#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct UnionFind{
	long long p[MAX];
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		if(p[a] < p[b]){
			p[a] += p[b];
			p[b] = a;
		}
		else{
			p[b] += p[a];
			p[a] = b;
		}
		return true;
	}
};

int main(){
	int N, M;
	UnionFind UF;
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		UF.p[i] = -val;
	}
	for(int i = 0; i < M; ++i){
		int a, b;
		scanf("%d %d", &a, &b);
		UF.u(--a, --b);
		printf("%lld\n", -UF.p[UF.f(a)]);
	}
}