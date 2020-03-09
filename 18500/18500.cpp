#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 100;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};

int main(){
	int R, C, N, H[MAX];
	char map[MAX][MAX];
	scanf("%d %d\n", &R, &C);
	for(int i = R-1; i >= 0; --i){
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
		getchar();
	}
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d", H+i);
		--H[i];
	}

	for(int k = 0; k < N; ++k){
		int hr = -1, hc = -1;
		if(k%2){
			for(int j = C-1; j >= 0; --j){
				if(map[H[k]][j] == 'x'){
					map[H[k]][j] = '.';
					hr = H[k];
					hc = j;
					break;
				}
			}
		}
		else{
			for(int j = 0; j < C; ++j){
				if(map[H[k]][j] == 'x'){
					map[H[k]][j] = '.';
					hr = H[k];
					hc = j;
					break;
				}
			}
		}
		if(hr == -1) continue;

		for(int l = 0; l < 4; ++l){
			int sr = hr + roff[l], sc = hc + coff[l];
			if(sr < 0 || sr >= R || sc < 0 || sc >= C || map[sr][sc] != 'x') continue;

			bool visited[MAX][MAX] = {false,}, onGround = false;
			queue<int> Q;
			visited[sr][sc] = true;
			Q.push(sr*MAX + sc);
			while(!Q.empty()){
				int r = Q.front() / MAX, c = Q.front() % MAX;
				Q.pop();
				if(r == 0){
					onGround = true;
					break;
				}
				for(int d = 0; d < 4; ++d){
					int nr = r + roff[d], nc = c + coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'x') continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*MAX + nc);
					}
				}
			}
			if(onGround) continue;

			int fallH = R;
			for(int i = 1; i < R; ++i){
				for(int j = 0; j < C; ++j){
					if(!visited[i][j]) continue;

					int tempH = 0;
					for(int h = i-1; h >= 0; --h){
						if(map[h][j] == 'x' && !visited[h][j]) break;
						++tempH;
					}
					fallH = min(fallH, tempH);
				}
			}
			for(int i = 0; i < R; ++i)
				for(int j = 0; j < C; ++j)
					if(visited[i][j]) swap(map[i-fallH][j], map[i][j]);
			break;
		}
	}

	for(int i = R-1; i >= 0; --i){
		for(int j = 0; j < C; ++j)
			putchar(map[i][j]);
		puts("");
	}
}