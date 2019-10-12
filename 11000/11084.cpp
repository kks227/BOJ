#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 400;
const int INF = 1e9;
const int roff[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int coff[8] = {-1, 1, -2, 2, -2, 2, -1, 1};
const int MOD = 1000000009;

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	int dist[MAX][MAX] = {0,};
	bool visited[MAX][MAX] = {true,};
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
		for(int d = 0; d < 8; ++d){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				dist[nr][nc] = dist[r][c] + 1;
				Q.push(nr*MAX + nc);
			}
		}
	}
	if(!visited[R-1][C-1]) puts("None");
	else{
		int cnt[MAX][MAX] = {1,};
		memset(visited, 0, sizeof(visited));
		visited[0][0] = true;
		Q.push(0);
		while(!Q.empty()){
			int qSize = Q.size();
			for(int i = 0; i < qSize; ++i){
				int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
				for(int d = 0; d < 8; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || dist[r][c]+1 != dist[nr][nc]) continue;
					cnt[nr][nc] = (cnt[nr][nc] + cnt[r][c]) % MOD;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*MAX + nc);
					}
				}
			}
		}
		printf("%d %d\n", dist[R-1][C-1], cnt[R-1][C-1]);
	}
}