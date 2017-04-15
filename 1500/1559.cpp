#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
typedef tuple<int, int, int, int> Node;

int main(){
	while(1){
		int R, C;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		char map[100][100];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				switch(getchar()){
					case 'N': map[i][j] = 0; break;
					case 'E': map[i][j] = 1; break;
					case 'S': map[i][j] = 2; break;
					default : map[i][j] = 3;
				}
			}
		}
		int K, gift[100][100] = {0};
		scanf("%d", &K);
		for(int i=0; i<K; i++){
			int r, c;
			scanf("%d %d", &r, &c);
			gift[r-1][c-1] = i+1;
		}

		bool visited[100][100][4][1<<8] = {1};
		queue<Node> Q;
		Q.push(Node(0, 0, 0, 0));
		bool success = false;
		for(int result=0; ; result++){
			int qSize = Q.size();
			for(int i=0; i<qSize; i++){
				int r, c, t, got;
				tie<int, int, int, int>(r, c, t, got) = Q.front();
				Q.pop();
				if(r == R-1 && c == C-1 && got == (1<<K)-1){
					printf("%d\n", result);
					success = true;
					break;
				}

				int nt = (t+1)%4;
				if(!visited[r][c][nt][got]){
					visited[r][c][nt][got] = true;
					Q.push(Node(r, c, nt, got));
				}
				int d = (map[r][c]+t)%4, nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
				int ngot = got;
				if(gift[nr][nc]) ngot |= 1 << gift[nr][nc]-1;
				if(!visited[nr][nc][nt][ngot]){
					visited[nr][nc][nt][ngot] = true;
					Q.push(Node(nr, nc, nt, ngot));
				}
			}
			if(success) break;
		}
	}
}