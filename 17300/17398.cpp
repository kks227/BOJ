#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	long long u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return 0;
		long long result = 1LL * p[a] * p[b];
		if(p[a] < p[b]){
			p[a] += p[b];
			p[b] = a;
		}
		else{
			p[b] += p[a];
			p[a] = b;
		}
		return result;
	}
};

int main(){
	int N, M, Q, u[MAX], v[MAX], ee[MAX];
	bool erased[MAX] = {false,};
	scanf("%d %d %d", &N, &M, &Q);
	for(int i = 0; i < M; ++i){
		scanf("%d %d", u+i, v+i);
		--u[i]; --v[i];
	}
	for(int i = 0; i < Q; ++i){
		scanf("%d", ee+i);
		erased[--ee[i]] = true;
	}
	
	UnionFind UF;
	long long result = 0;
	for(int i = 0; i < M; ++i)
		if(!erased[i]) UF.u(u[i], v[i]);
	for(int i = Q-1; i >= 0; --i)
		result += UF.u(u[ee[i]], v[ee[i]]);
	printf("%lld\n", result);
}