#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};

int main(){
	int R, C, map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &map[i][j]);

	queue<int> Q;
	bool visited[MAX][MAX][4][2] = {true,};
	Q.push(0);
	for(int result = 0; !Q.empty(); ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int r = Q.front()/(MAX*8), c = Q.front()%(MAX*8)/8, pd = Q.front()%8/2;
			bool oranged = Q.front()%2;
			Q.pop();
			if(r == R-1 && c == C-1){
				printf("%d\n", result);
				return 0;
			}

			bool flag = true;
			if(map[r][c] == 4){
				flag = false;
				int nr = r+roff[pd], nc = c+coff[pd];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 0 || map[nr][nc] == 3){
					flag = true;
					oranged = false;
				}
				else if(!visited[nr][nc][pd][0]){
					visited[nr][nc][pd][0] = true;
					Q.push(nr*MAX*8 + nc*8 + pd*2);
				}
			}
			if(flag){
				if(map[r][c] == 2) oranged = true;
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
					if(map[nr][nc] == 0 || map[nr][nc] == 3 && !oranged) continue;
					if(!visited[nr][nc][d][oranged]){
						visited[nr][nc][d][oranged] = true;
						Q.push(nr*MAX*8 + nc*8 + d*2 + oranged);
					}
				}
			}
		}
	}
	puts("-1");
}