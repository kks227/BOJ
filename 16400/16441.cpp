#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	char map[100][100];
	bool visited[100][100] = {false,};
	queue<int> Q;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == 'W'){
				visited[i][j] = true;
				Q.push(i*100 + j);
			}
		}
	}

	while(!Q.empty()){
		int r = Q.front()/100, c = Q.front()%100;
		Q.pop();
		for(int d = 0; d < 4; ++d){
			int nr = r+roff[d], nc = c+coff[d];
			if(map[nr][nc] == '#') continue;
			if(map[nr][nc] == '+'){
				while(map[nr+roff[d]][nc+coff[d]] != '#' && map[nr][nc] != '.'&& map[nr][nc] != 'W'){
					nr += roff[d];
					nc += coff[d];
				}
			}
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*100 + nc);
			}
		}
	}

	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == '.' && !visited[i][j]) putchar('P');
			else putchar(map[i][j]);
		}
		puts("");
	}
}