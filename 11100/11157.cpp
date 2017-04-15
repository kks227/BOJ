#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
const int roff[4] = {0, -1, 0, 1};
const int coff[4] = {1, 0, -1, 0};
const char dirc[4] = {'E', 'N', 'W', 'S'};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, r, c, sr, sc, dr, dc, prev[500][500];
		char map[500][500], path[500][500];
		scanf("%d %d %d %d %d %d", &C, &R, &sc, &sr, &dc, &dr);
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] <= '9') map[i][j] -= '0';
				else map[i][j] -= 'A'-10;
			}
		}

		bool visited[500][500] = {0};
		visited[sr][sc] = true;
		queue<int> Q;
		Q.push(sr*1000+sc);
		while(1){
			r = Q.front()/1000;
			c = Q.front()%1000;
			Q.pop();
			if(r == dr && c == dc) break;

			for(int d=0; d<4; d++){
				if(!(map[r][c] & 1<<d)) continue;
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
				visited[nr][nc] = true;
				Q.push(nr*1000+nc);
				prev[nr][nc] = r*1000+c;
				path[nr][nc] = d;
			}
		}

		vector<char> result;
		while(r != sr || c != sc){
			result.push_back(path[r][c]);
			tie<int, int>(r, c) = tuple<int, int>(prev[r][c]/1000, prev[r][c]%1000);
		}
		int doff = 0;
		for(int i=result.size()-1; i>=0; i--){
			putchar(dirc[ (result[i]+doff)%4 ]);
			r += roff[result[i]];
			c += coff[result[i]];
			if(map[r][c] & 16) doff = (doff+1)%4;
		}
		puts("");
	}
}