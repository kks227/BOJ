#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
const int INF = 1e9;

int main(){
	int R, C, sr = -1, sc, er, ec, dist[100][100][4];
	char map[100][100];
	scanf("%d %d", &C, &R);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'C'){
				if(sr == -1){ sr = i; sc = j; }
				else{ er = i; ec = j; }
			}
			for(int d=0; d<4; d++)
				dist[i][j][d] = INF;
		}
	}

	queue<int> Q;
	for(int d=0; d<4; d++){
		for(int k=0; ; k++){
			int r = sr + roff[d]*k, c = sc + coff[d]*k;
			if(r < 0 || r >= R || c < 0 || c >= C || map[r][c] == '*') break;
			dist[r][c][d] = 0;
			Q.push(d*10000 + r*100 + c);
		}
	}
	for(int i=1; !Q.empty(); i++){
		int qSize = Q.size();
		for(int j=0; j<qSize; j++){
			int cr = Q.front()%10000/100, cc = Q.front()%100, cd = Q.front()/10000;
			Q.pop();
			for(int d=0; d<4; d++){
				if(d == cd) continue;
				for(int k=0; ; k++){
					int r = cr + roff[d]*k, c = cc + coff[d]*k;
					if(r < 0 || r >= R || c < 0 || c >= C || map[r][c] == '*' || dist[r][c][d] < INF) break;
					dist[r][c][d] = i;
					Q.push(d*10000 + r*100 + c);
				}
			}
		}
	}

	int result = INF;
	for(int d=0; d<4; d++)
		result = min(dist[er][ec][d], result);
	printf("%d\n", result);
}