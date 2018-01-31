#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, er, ec;
	bool map[1000][1000], visited[1000][1000][2] = {0};
	scanf("%d %d %d %d %d %d", &R, &C, &sr, &sc, &er, &ec);
	sr--; sc--; er--; ec--;
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	queue<int> Q;
	Q.push(sr*1000+sc);
	visited[sr][sc][0] = true;

	for(int result = 0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			bool b = Q.front() / 1000000;
			int r = Q.front() % 1000000 / 1000, c = Q.front() % 1000; Q.pop();
			if(r == er && c == ec){
				printf("%d\n", result);
				return 0;
			}

			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				if(b && map[nr][nc]) continue;
				bool nb = b || map[nr][nc];
				if(!visited[nr][nc][nb]){
					visited[nr][nc][nb] = true;
					Q.push(nb*1000000 + nr*1000 + nc);
				}
			}
		}
	}
	puts("-1");
}