#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &C, &R);
		if(R == 0) break;

		bool pass[30][30][4] = {0};
		for(int i=0; ; i++){
			for(int j=0; j<C-1; j++){
				int b;
				scanf("%d", &b);
				pass[i][j][3] = pass[i][j+1][2] = !b;
			}
			if(i == R-1) break;
			for(int j=0; j<C; j++){
				int b;
				scanf("%d", &b);
				pass[i][j][1] = pass[i+1][j][0] = !b;
			}
		}

		bool visited[30][30] = {1,}, success = false;
		queue<int> Q;
		Q.push(0);
		for(int result=1; !Q.empty(); result++){
			int qSize = Q.size();
			for(int i=0; i<qSize; i++){
				int r = Q.front()/100, c = Q.front()%100;
				Q.pop();
				if(r == R-1 && c == C-1){
					printf("%d\n", result);
					success = true;
					break;
				}
				for(int d=0; d<4; d++){
					if(!pass[r][c][d]) continue;
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
					visited[nr][nc] = true;
					Q.push(nr*100+nc);
				}
			}
			if(success) break;
		}
		if(!success) puts("0");
	}
}