#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 100;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int R, C, result = 0;
	char map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}

	bool visited[MAX][MAX] = {false,};
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == '.' || visited[i][j]) continue;

			queue<int> Q;
			Q.push(i*MAX + j);
			visited[i][j] = true;
			while(!Q.empty()){
				int r = Q.front()/MAX, c = Q.front()%MAX;
				Q.pop();
				for(int d = 0; d < 8; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '.') continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*MAX + nc);
					}
				}
			}
			++result;
		}
	}
	printf("%d\n", result);
}