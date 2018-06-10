#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind{
	int p[100000];
	UnionFind(){ fill(p, p+100000, -1); }
	int find(int a){
		if(p[a] < 0) return a;
		return p[a] = find(p[a]);
	}
	void merge(int a, int b, bool flag){
		a = find(a);
		b = find(b);
		if(a == b) return;
		if(p[a] <= p[b]){
			p[a] += p[b]*(flag?-1:1);
			p[b] = a;
		}
		else{
			p[b] += p[a]*(flag?-1:1);
			p[a] = b;
		}
	}
};

int main(){
	int N, M;
	UnionFind UF;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		UF.p[i] = -A;
	}
	for(int i=0; i<M; i++){
		int o, p, q;
		scanf("%d %d %d", &o, &p, &q);
		p--; q--;
		UF.merge(p, q, o-1);
	}
	vector<int> result;
	for(int i=0; i<N; i++)
		if(UF.p[i] < 0) result.push_back(-UF.p[i]);
	sort(result.begin(), result.end());
	printf("%d\n", result.size());
	for(int i: result)
		printf("%d ", i);
}