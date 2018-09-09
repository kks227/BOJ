#include <cstdio>
#include <queue>
using namespace std;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		char map[100][100];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++)
				map[i][j] = getchar();
		}

		int result = 0;
		bool visited[100][100] = {false};
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				if(visited[i][j] || map[i][j] == '*') continue;

				queue<int> Q;
				Q.push(i*100 + j);
				visited[i][j] = true;
				while(!Q.empty()){
					int r = Q.front()/100, c = Q.front()%100;
					Q.pop();
					for(int d=0; d<8; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '*') continue;
						if(!visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*100 + nc);
						}
					}
				}
				result++;
			}
		}
		printf("%d\n", result);
	}
}