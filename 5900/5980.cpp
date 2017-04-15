#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, sr, sc, er, ec, wr[26][2], wc[26][2], wcnt[26] = {0};
	char map[300][300];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == '@'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == '='){
				er = i;
				ec = j;
			}
			else if(isupper(map[i][j])){
				int c = map[i][j] - 'A';
				wr[c][wcnt[c]] = i;
				wc[c][wcnt[c]] = j;
				wcnt[c]++;
			}
		}
	}

	queue<int> Q;
	Q.push(sr*1000+sc);
	bool visited[300][300] = {0};
	visited[sr][sc] = true;
	for(int result=0; ; result++){
		if(visited[er][ec]){
			printf("%d\n", result);
			break;
		}

		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/1000, c = Q.front()%1000;
			Q.pop();
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
				if(isupper(map[nr][nc])){
					int c = map[nr][nc] - 'A';
					for(int j=0; j<2; j++){
						if(nr != wr[c][j] || nc != wc[c][j]){
							nr = wr[c][j];
							nc = wc[c][j];
							break;
						}
					}
				}
				if(!visited[nr][nc]){
					visited[nr][nc] = true;
					Q.push(nr*1000+nc);
				}
			}
		}
	}
}