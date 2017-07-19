#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N, M, T, H[100], ind[100], dp[100][501];
vector<int> adj[100];

int isle(int curr, int k){
	int &ret = dp[curr][k];
	if(ret != -1) return ret;
	if(k == 0) return ret = H[curr];

	ret = INF;
	for(int next: adj[curr])
		ret = min(ret, isle(next, k-1));
	return ret;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", H+i);
	for(int i=0; i<M; i++){
		int X, Y;
		scanf("%d %d", &X, &Y);
		ind[--X]++; ind[--Y]++;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}
	memset(dp, -1, sizeof(dp));
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		int A, K;
		scanf("%d %d", &A, &K);
		A--;
		printf("%d\n", ind[A] ? isle(A, K) : -1);
	}
}