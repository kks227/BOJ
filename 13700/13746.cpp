#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 50;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	char map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}

	int result = 0;
	queue<int> Q;
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == 'W') continue;
			Q.push(i*MAX + j);
			bool flag = (map[i][j] == 'L');
			map[i][j] = 'W';
			while(!Q.empty()){
				int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'W') continue;
					Q.push(nr*MAX + nc);
					if(map[nr][nc] == 'L') flag = true;
					map[nr][nc] = 'W';
				}
			}
			if(flag) ++result;
		}
	}
	printf("%d\n", result);
}