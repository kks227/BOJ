#include <cstdio>
#include <vector>
#include <set>
#include <unordered_map>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef tuple<int, int, int> T;

struct UnionFind{
	int p[MAX];
	UnionFind(){ fill(p, p+MAX, -1); }
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
	int size(int a){ return -p[f(a)]; }
};



int main(){
	int N, Q;
	T e[MAX], q[MAX];
	set<int> S;
	scanf("%d %d", &N, &Q);
	for(int i = 0; i < N-1; ++i){
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		e[i] = T(w, u-1, v-1);
		S.insert(w);
	}
	for(int i = 0; i < Q; ++i){
		int k, v;
		scanf("%d %d", &k, &v);
		S.insert(k);
		q[i] = T(k, v-1, i);
	}

	unordered_map<int, int> hash;
	int H = 0;
	for(int i: S)
		hash[i] = H++;
	for(int i = 0; i < N-1; ++i)
		get<0>(e[i]) = hash[get<0>(e[i])];
	for(int i = 0; i < Q; ++i)
		get<0>(q[i]) = hash[get<0>(q[i])];
	sort(e, e+N-1);
	reverse(e, e+N-1);
	sort(q, q+Q);
	reverse(q, q+Q);

	UnionFind UF;
	int result[MAX];
	for(int i = H-1, j = 0, k = 0; i >= 0; --i){
		for(; j < N-1 && get<0>(e[j]) == i; ++j)
			UF.u(get<1>(e[j]), get<2>(e[j]));
		for(; k < Q && get<0>(q[k]) == i; ++k)
			result[get<2>(q[k])] = UF.size(get<1>(q[k])) - 1;
	}

	for(int i = 0; i < Q; ++i)
		printf("%d\n", result[i]);
}