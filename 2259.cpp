#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 6667;

int dp[MAX];
vector<int> adj[MAX];

inline long long pow2(int n){ return 1LL*n*n; }

int maxMonty(int curr){
	int &ret = dp[curr];
	if(ret != -1) return ret;

	ret = 0;
	for(int next: adj[curr])
		ret = max(ret, maxMonty(next));
	return ++ret;
}

int main(){
	int N, S, x[MAX], y[MAX], t[MAX];
	scanf("%d %d", &N, &S);
	x[0] = y[0] = t[0] = 0;
	for(int i=1; i<=N; i++)
		scanf("%d %d %d", x+i, y+i, t+i);

	N++;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++){
			if(i == j || t[i] > t[j]) continue;
			if(x[i]==x[j] && y[i]==y[j] && t[i]==t[j]){
				if(i < j) adj[i].push_back(j);
				continue;
			}

			long long d1 = pow2(x[i]-x[j]) + pow2(y[i]-y[j]);
			long long d2 = pow2(S*(t[j]-t[i]));
			if(d2 >= d1) adj[i].push_back(j);
		}

	memset(dp, -1, sizeof(dp));
	printf("%d\n", maxMonty(0)-1);
}