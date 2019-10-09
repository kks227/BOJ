#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> P;

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
		if(p[a] > p[b]) swap(a, b);
		p[a] += p[b];
		p[b] = a;
		return true;
	}
	long long size(int a){ return -p[f(a)]; }
};

int main(){
	int N;
	long long M;
	scanf("%d %lld", &N, &M);
	P p[MAX];
	UnionFind UF;
	for(int i = 0; i < N; ++i){
		int F, S;
		scanf("%d %d", &F, &S);
		UF.p[i] = -F;
		p[i] = P(S, i);
	}
	sort(p, p+N);

	bool visited[MAX] = {false,};
	for(int i = 0; i < N; ++i){
		int j = p[i].second;
		visited[j] = true;
		if(j > 0 && visited[j-1]) UF.u(j, j-1);
		if(j < N-1 && visited[j+1]) UF.u(j, j+1);
		if(UF.size(j) >= M){
			printf("%d\n", p[i].first);
			break;
		}
	}
}