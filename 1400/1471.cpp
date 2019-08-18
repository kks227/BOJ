#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 200001;

int N, to[MAX], dp[MAX];
bool visited[MAX];

int candy(int u){
	int &ret = dp[u];
	if(ret != -1) return ret;
	visited[u] = true;
	int v = u, k = u;
	while(k > 0){
		v += k%10;
		k /= 10;
	}
	if(v > N) v -= N;
	to[u] = v;
	
	if(visited[v]){
		if(dp[v] != -1) return ret = dp[v] + 1;
		ret = 1;
		for(int w = v; w != u; w = to[w]) ++ret;
		for(int w = v; w != u; w = to[w]) dp[w] = ret;
		return ret;
	}
	candy(v);
	if(ret == -1) return ret = candy(v) + 1;
	return ret;
}

int main(){
	scanf("%d", &N);
	fill(dp, dp+MAX, -1);
	int result = 0;
	for(int i = 1; i <= N; ++i)
		result = max(candy(i), result);
	printf("%d\n", result);
}