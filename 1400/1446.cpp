#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int N, D, dp[10001];
vector<P> adj[10001];

int shortcut(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;
	if(curr == D) return ret = 0;

	ret = shortcut(curr+1) + 1;
	for(auto &p: adj[curr])
		ret = min(ret, shortcut(p.first) + p.second);
	return ret;
}

int main(){
	scanf("%d %d", &N, &D);
	for(int i=0; i<N; i++){
		int s, e, d;
		scanf("%d %d %d", &s, &e, &d);
		adj[s].push_back(P(e, d));
	}
	fill(dp, dp+10001, -1);
	printf("%d\n", shortcut(0));
}