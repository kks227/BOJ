#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C, map[1000][1000], cnt = 0, result = 0;
	scanf("%d %d", &C, &R);
	queue<int> Q;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] >= 0) cnt++;
			if(map[i][j] == 1) Q.push(i*1000 + j);
		}
	}

	for(; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/1000, c = Q.front()%1000; Q.pop();
			cnt--;
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 0) continue;
				map[nr][nc] = 1;
				Q.push(nr*1000 + nc);
			}
		}
		if(cnt == 0) break;
	}
	printf("%d\n", cnt ? -1 : result);
}