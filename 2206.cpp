#include <cstdio>
#include <queue>
using namespace std;

const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, M;
	bool map[1000][1000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &map[i][j]);

	bool visited[2][1000][1000] = {0};
	visited[0][0][0] = true;
	queue<int> Q;
	Q.push(0);
	int result = 1;

	while(!Q.empty()){
		int qSize = Q.size();
		bool reach = false;
		for(int i=0; i<qSize; i++){
			bool crash = Q.front() / (N*M);
			int r = Q.front() % (N*M) / M;
			int c = Q.front() % M;
			Q.pop();
			if(r==N-1 && c==M-1){
				reach = true;
				break;
			}

			for(int d=0; d<4; d++){
				int nr = r + roff[d];
				int nc = c + coff[d];
				if(nr<0 || nr>=N || nc<0 || nc>=M) continue;
				if(visited[crash][nr][nc]) continue;
				if(map[nr][nc]){
					if(crash) continue;
					visited[1][nr][nc] = true;
					Q.push(N*M + nr*M + nc);
				}
				else{
					visited[crash][nr][nc] = true;
					Q.push(crash*N*M + nr*M + nc);
				}
			}
		}
		if(reach) break;
		result++;
	}
	if(visited[0][N-1][M-1] || visited[1][N-1][M-1]) printf("%d\n", result);
	else puts("-1");
}