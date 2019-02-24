#include <cstdio>
#include <cmath>
#include <queue>
using namespace std;
const int MAX = 500;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, er, ec, acnt = 0;
	char map[MAX][MAX];
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
	}
	scanf("%d %d %d %d", &sr, &sc, &er, &ec);
	--sr; --sc; --er; --ec;
	for(int d = 0; d < 4; ++d){
		int r = er+roff[d], c = ec+coff[d];
		if(r >= 0 && r < R && c >= 0 && c < C && map[r][c] == '.') ++acnt;
	}
	int sed = abs(sr-er) + abs(sc-ec);

	bool result = true;
	if(sed == 0){
		result = (acnt > 0);
	}
	else if(sed == 1){
		result = (map[er][ec] == 'X' || acnt > 1 || acnt == 1 && map[sr][sc] == 'X');
	}
	else{
		queue<int> Q;
		Q.push(sr*MAX + sc);
		bool visited[MAX][MAX] = {false,};
		visited[sr][sc] = true;
		while(!Q.empty()){
			int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(!visited[nr][nc] && (nr == er && nc == ec || map[nr][nc] == '.')){
					visited[nr][nc] = true;
					Q.push(nr*MAX + nc);
				}
			}
		}
		if(!visited[er][ec]) result = false;
		else if(map[er][ec] == '.') result = (acnt > 1);
		else result = true;
	}
	puts(result ? "YES" : "NO");
}