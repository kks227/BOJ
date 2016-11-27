#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
	int R, C, N, roff[10], coff[10];
	bool map[1000][1000];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", roff+i, coff+i);

	bool visited[1000][1000] = {0};
	queue<int> Q;
	for(int i=0; i<C; i++){
		if(map[0][i]){
			visited[0][i] = true;
			Q.push(i);
		}
	}

	int result = 0;
	bool success = false;
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/1000, c = Q.front()%1000;
			Q.pop();
			if(r == R-1){
				success = true;
				break;
			}

			for(int d=0; d<N; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr<0 || nr>=R || nc<0 || nc>=C || !map[nr][nc] || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr*1000 + nc);
			}
		}
		if(success) break;
		result++;
	}
	printf("%d\n", success ? result : -1);
}