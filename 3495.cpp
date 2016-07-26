#include <cstdio>
#include <queue>
using namespace std;

int off[2][4] = {-1, 1, 0, 0, 0, 0, -1, 1};
int nd1[4] = {2, 3, 0, 1};
int nd2[4] = {3, 2, 1, 0};

int main(){
	int H, W;
	char map[102][102];
	for(int i=0; i<102; i++)
		for(int j=0; j<102; j++)
			map[i][j] = '.';
	scanf("%d %d", &H, &W);
	for(int i=1; i<=H; i++){
		getchar();
		for(int j=1; j<=W; j++)
			map[i][j] = getchar();
	}

	int line = 0, out = 1;
	queue<int> Q;
	Q.push(0);
	bool visited[102][102] = {1};
	while(!Q.empty()){
		int r = Q.front()/1000;
		int c = Q.front()%1000;
		Q.pop();
		for(int d=0; d<4; d++){
			int nr = r + off[0][d];
			int nc = c + off[1][d];
			if(nr<0 || nr>=H+2 || nc<0 || nc>=W+2 || visited[nr][nc]) continue;

			int nd = d;
			bool newVisit = true;
			while(map[nr][nc] != '.'){
				line++;
				visited[nr][nc] = true;
				nd = (map[nr][nc] == '\\' ? nd1 : nd2)[nd] % 4;
				nr += off[0][nd];
				nc += off[1][nd];
				if(visited[nr][nc]){
					newVisit = false;
					break;
				}
			}
			if(!newVisit) continue;
			visited[nr][nc] = true;
			out++;
			Q.push(nr*1000+nc);
		}
	}
	printf("%d\n", (W+2)*(H+2)-out - line/2);
}