#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
int N, K, X[1002], Y[1002], dist[1002][1002];

int main(){
	scanf("%d %d", &N, &K);
	if(K > N) K = N;
	X[0] = Y[0] = dist[0][0] = 0;
	X[N+1] = Y[N+1] = 10000;
	N += 2;
	for(int i=1; i<=N; i++){
		if(i<N-1) scanf("%d %d", X+i, Y+i);
		for(int j=0; j<i; j++){
			double d = sqrt(pow(X[i]-X[j], 2) + pow(Y[i]-Y[j], 2))/10;
			dist[i][j] = dist[j][i] = (int)d + (d != (int)d);
		}
		dist[i][i] = 0;
	}
	queue<int> q;
	int lo = 0, hi = 1500;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		bool visited[1002] = {0};
		q.push(0);
		int remain = K+2;
		while(remain--){
			int qSize = q.size();
			for(int i=0; i<qSize; i++){
				int u = q.front();
				q.pop();
				if(visited[u]) continue;
				visited[u] = true;
				if(u == N-1) break;
				for(int i=1; i<N; i++)
					if(dist[u][i] <= mid && !visited[i]) q.push(i);
			}
			if(visited[N-1]) break;
		}
		while(!q.empty()) q.pop();
		(visited[N-1] ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}