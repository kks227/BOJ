#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct UnionFind{
	int p[100000];
	UnionFind(){ fill(p, p+100000, -1); }
	int find(int a){
		if(p[a] < 0) return a;
		return p[a] = find(p[a]);
	}
	int size(int a){ return -p[find(a)]; }
	bool merge(int a, int b){
		a = find(a);
		b = find(b);
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
	int N, M, C, H, K;
	scanf("%d %d", &N, &M);
	UnionFind UF;
	for(int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		UF.merge(u-1, v-1);
	}
	scanf("%d %d %d", &C, &H, &K);
	C--; H--;

	int result = UF.size(C);
	priority_queue<int> PQ;
	for(int i=0; i<N; i++)
		if(UF.p[i] < 0 && UF.find(i) != UF.find(C) && UF.find(i) != UF.find(H)) PQ.push(UF.size(i));
	for(int i=0; i<K && !PQ.empty(); i++){
		result += PQ.top();
		PQ.pop();
	}
	printf("%d\n", result);
}