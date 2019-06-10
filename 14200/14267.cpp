#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 100000;

int N, M, val[MAX];
vector<int> child[MAX];

void dfs(int curr, int v){
	val[curr] += v;
	for(int next: child[curr])
		dfs(next, val[curr]);
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int k;
		scanf("%d", &k);
		if(k > 0) child[k-1].push_back(i);
	}
	for(int i = 0; i < M; ++i){
		int u, v;
		scanf("%d %d", &u, &v);
		val[u-1] += v;
	}
	dfs(0, 0);
	for(int i = 0; i < N; ++i)
		printf("%d ", val[i]);
}