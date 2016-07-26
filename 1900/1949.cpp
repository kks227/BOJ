#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int N, val[10000], dp[10000][2];
vector<int> adj[10000], child[10000];
bool visited[10000];

void setChildren(int curr){
	visited[curr] = true;
	for(int next: adj[curr])
		if(!visited[next]){
			child[curr].push_back(next);
			setChildren(next);
		}
}

int goodTown(int curr, bool isGood){
	int &ret = dp[curr][isGood];
	if(ret != -1) return ret;

	ret = 0;
	for(int next: child[curr]){
		int temp = goodTown(next, false);
		if(!isGood) temp = max(temp, goodTown(next, true));
		ret += temp;
	}
	return ret += (isGood ? val[curr] : 0);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", val+i);
	for(int i=0; i<N-1; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1].push_back(v-1);
		adj[v-1].push_back(u-1);
	}
	setChildren(0);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", max(goodTown(0, false), goodTown(0, true)));
}