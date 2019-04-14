#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int main(){
	int R, C, w, h, sr, sc, er, ec, pSum[2][MAX][MAX+1] = {0,};
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int val;
			scanf("%d", &val);
			pSum[0][i][j+1] = pSum[0][i][j] + val;
			pSum[1][j][i+1] = pSum[1][j][i] + val;
		}
	}
	scanf("%d %d %d %d %d %d", &h, &w, &sr, &sc, &er, &ec);
	--sr; --sc; --er; --ec;

	bool visited[MAX][MAX] = {false,};
	visited[sr][sc] = true;
	queue<int> Q;
	Q.push(sr*MAX + sc);
	for(int result = 0; !Q.empty(); ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int r = Q.front()/MAX, c = Q.front()%MAX;
			Q.pop();
			if(r == er && c == ec){
				printf("%d\n", result);
				return 0;
			}

			if(r > 0 && !visited[r-1][c] && pSum[0][r-1][c+w] == pSum[0][r-1][c]){
				visited[r-1][c] = true;
				Q.push((r-1)*MAX + c);
			}
			if(r < R-h && !visited[r+1][c] && pSum[0][r+h][c+w] == pSum[0][r+h][c]){
				visited[r+1][c] = true;
				Q.push((r+1)*MAX + c);
			}
			if(c > 0 && !visited[r][c-1] && pSum[1][c-1][r+h] == pSum[1][c-1][r]){
				visited[r][c-1] = true;
				Q.push(r*MAX + c-1);
			}
			if(c < C-w && !visited[r][c+1] && pSum[1][c+w][r+h] == pSum[1][c+w][r]){
				visited[r][c+1] = true;
				Q.push(r*MAX + c+1);
			}
		}
	}
	puts("-1");
}