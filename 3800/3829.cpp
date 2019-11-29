#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int MAX = 50;
const short SINF = 1e4;
const int INF = 1e9;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int rkpos[4] = {0, 0, 1, 1};
const int ckpos[4] = {0, 1, 0, 1};
const int rbpos[8] = {-1, -1, 0, 1, 2, 2, 1, 0};
const int cbpos[8] = {0, 1, 2, 2, 1, 0, -1, -1};
typedef pair<int, int> P;

int main(){
	while(1){
		int R, C, skr = -1, skc, sbr[2], sbc[2], sbcnt = 0;
		bool kFlag[MAX][MAX] = {false,};
		char map[MAX][MAX];
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				if(map[i][j] == '.'){
					sbr[sbcnt] = i;
					sbc[sbcnt++] = j;
					map[i][j] = 'o';
				}
				else if(map[i][j] == 'X'){
					if(skr == -1){
						skr = i;
						skc = j;
					}
					map[i][j] = 'o';
				}
			}
		}
		if(skr == 0 && skc == 0){
			puts("0");
			continue;
		}

		for(int i = 0; i < R-1; ++i){
			for(int j = 0; j < C-1; ++j){
				kFlag[i][j] = true;
				for(int l = 0; l < 4; ++l){
					if(map[i+rkpos[l]][j+ckpos[l]] != 'o'){
						kFlag[i][j] = false;
						break;
					}
				}
			}
		}

		short bDist[8][MAX][MAX][MAX][MAX];
		for(int k = 0; k < 8; ++k)
			for(int i = 0; i < R; ++i)
				for(int j = 0; j < C; ++j)
					for(int a = 0; a < R; ++a)
						for(int b = 0; b < C; ++b)
							bDist[k][i][j][a][b] = SINF;
		for(int k = 0; k < 8; ++k){
			for(int i = 0; i < R-1; ++i){
				for(int j = 0; j < C-1; ++j){
					if(!kFlag[i][j]) continue;

					for(int l = 0; l < 4; ++l)
						map[i+rkpos[l]][j+ckpos[l]] = 'X';

					int sr = i + rbpos[k], sc = j + cbpos[k];
					bDist[k][i][j][sr][sc] = 0;
					queue<int> Q;
					Q.push(sr*MAX + sc);
					while(!Q.empty()){
						int r = Q.front() / MAX, c = Q.front() % MAX;
						Q.pop();
						for(int d = 0; d < 4; ++d){
							int nr = r+roff[d], nc = c+coff[d];
							if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'o') continue;
							if(bDist[k][i][j][nr][nc] == SINF){
								bDist[k][i][j][nr][nc] = bDist[k][i][j][r][c] + 1;
								Q.push(nr*MAX + nc);
							}
						}
					}

					for(int l = 0; l < 4; ++l)
						map[i+rkpos[l]][j+ckpos[l]] = 'o';
				}
			}
		}

		int result = INF, dist[8][8][MAX][MAX];
		bool visited[8][8][MAX][MAX] = {false,};
		priority_queue<P, vector<P>, greater<P>> PQ;
		for(int k = 0; k < 8; ++k)
			for(int l = 0; l < 8; ++l)
				for(int i = 0; i < R; ++i)
					for(int j = 0; j < C; ++j)
						dist[k][l][i][j] = INF;
		for(int a = 0; a < 8; ++a){
			int br1 = skr + rbpos[a], bc1 = skc + cbpos[a];
			if(br1 < 0 || br1 > R || bc1 < 0 || bc1 >= C || map[br1][bc1] != 'o') continue;
			short blankDist1 = bDist[a][skr][skc][sbr[0]][sbc[0]];
			if(blankDist1 == SINF) continue;
			for(int b = 0; b < 8; ++b){
				if(a == b) continue;
				int br2 = skr + rbpos[b], bc2 = skc + cbpos[b];
				if(br2 < 0 || br2 > R || bc2 < 0 || bc2 >= C || map[br2][bc2] != 'o') continue;
				short blankDist2 = bDist[b][skr][skc][sbr[1]][sbc[1]];
				if(blankDist2 == SINF) continue;

				int startDist = blankDist1 + blankDist2;
				if(startDist < SINF){
					dist[a][b][skr][skc] = startDist;
					PQ.push(P(startDist, a*8*MAX*MAX + b*MAX*MAX + skr*MAX + skc));
				}
			}
		}
		while(!PQ.empty()){
			int k, l, r, c, currDist;
			do{
				int temp = PQ.top().second;
				c = temp % MAX; temp /= MAX;
				r = temp % MAX; temp /= MAX;
				l = temp % 8; temp /= 8;
				k = temp;
				currDist = PQ.top().first;
				PQ.pop();
			}while(visited[k][l][r][c] && !PQ.empty());
			if(visited[k][l][r][c]) break;

			visited[k][l][r][c] = true;
			if(r == 0 && c == 0) result = min(currDist, result);
			int br1 = r + rbpos[k], bc1 = c + cbpos[k];
			int br2 = r + rbpos[l], bc2 = c + cbpos[l];

			for(int a = 0; a < 8; ++a){
				int nbr1 = r + rbpos[a], nbc1 = c + cbpos[a];
				if(nbr1 < 0 || nbr1 > R || nbc1 < 0 || nbc1 >= C || map[nbr1][nbc1] != 'o') continue;
				short blankDist1 = bDist[k][r][c][nbr1][nbc1];
				if(blankDist1 == SINF) continue;
				for(int b = 0; b < 8; ++b){
					if(a == b) continue;
					int nbr2 = r + rbpos[b], nbc2 = c + cbpos[b];
					if(nbr2 < 0 || nbr2 > R || nbc2 < 0 || nbc2 >= C || map[nbr2][nbc2] != 'o') continue;
					short blankDist2 = bDist[l][r][c][nbr2][nbc2];
					if(blankDist2 == SINF) continue;

					int temp = (a == l && b == k ? 0 : blankDist1 + blankDist2);
					int nextDist = currDist + temp;
					if(temp < SINF && dist[a][b][r][c] > nextDist){
						dist[a][b][r][c] = nextDist;
						PQ.push(P(nextDist, a*8*MAX*MAX + b*MAX*MAX + r*MAX + c));
					}
				}
			}

			if(k/2 == l/2){
				int d = k/2, nk = (k+4)%8, nl = (l+4)%8;
				int nr = r + roff[d], nc = c + coff[d];
				if(nr < 0 || nc < 0 || !kFlag[nr][nc]) continue;

				int nextDist = currDist + 1;
				if(dist[nk][nl][nr][nc] > nextDist){
					dist[nk][nl][nr][nc] = nextDist;
					PQ.push(P(nextDist, nk*8*MAX*MAX + nl*MAX*MAX + nr*MAX + nc));
				}
			}
		}

		if(result == INF) result = -1;
		printf("%d\n", result);
	}
}