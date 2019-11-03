#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 100;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, T, map[MAX][MAX];
	scanf("%d %d %d", &R, &C, &T);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &map[i][j]);
	bool visited[2][MAX][MAX] = {true,};
	queue<int> Q;
	Q.push(0);
	for(int result = 0; !Q.empty() && result <= T; ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int r = Q.front()%(MAX*MAX)/MAX, c = Q.front()%MAX;
			bool g = Q.front()/(MAX*MAX);
			Q.pop();
			if(r == R-1 && c == C-1){
				printf("%d\n", result);
				return 0;
			}
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				bool ng = g;
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(map[nr][nc] == 2) ng = true;
				else if(map[nr][nc] == 1 && !ng) continue;
				if(!visited[ng][nr][nc]){
					visited[ng][nr][nc] = true;
					Q.push(ng*MAX*MAX + nr*MAX + nc);
				}
			}
		}
	}
	puts("Fail");
}