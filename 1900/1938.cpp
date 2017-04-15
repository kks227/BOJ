#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const int rpos[2][3] = {{-1, 0, 1}, {0, 0, 0}};
const int cpos[2][3] = {{0, 0, 0}, {-1, 0, 1}};
typedef tuple<int, int, int> Node;

int main(){
	int N, sr = -1, sc, sx;
	char map[50][50];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'B'){
				if(sr != -1) map[i][j] = '0';
				else if(i > 0 && map[i-1][j] == 'B'){
					sr = i;
					sc = j;
					sx = 0;
					map[i-1][j] = map[i][j] = '0';
				}
				else if(j > 0 && map[i][j-1] == 'B'){
					sr = i;
					sc = j;
					sx = 1;
					map[i][j-1] = map[i][j] = '0';
				}
			}
		}
	}

	queue<Node> Q;
	Q.push(Node(sr, sc, sx));
	bool visited[50][50][2] = {0};
	visited[sr][sc][sx] = true;
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r, c, x;
			tie<int, int, int>(r, c, x) = Q.front();
			Q.pop();
			bool success = true;
			for(int j=0; j<3; j++)
				if(map[ r+rpos[x][j] ][ c+cpos[x][j] ] != 'E') success = false;
			if(success){
				printf("%d\n", result);
				return 0;
			}

			bool possible;
			for(int d=0; d<4; d++){
				int nr = r + roff[d], nc = c + coff[d];
				possible = true;
				for(int j=0; j<3; j++){
					int rr = nr + rpos[x][j], cc = nc + cpos[x][j];
					if(rr < 0 || rr >= N || cc < 0 || cc >= N || map[rr][cc] == '1') possible = false;
				}
				if(possible && !visited[nr][nc][x]){
					visited[nr][nc][x] = true;
					Q.push(Node(nr, nc, x));
				}
			}
			possible = true;
			for(int j=-1; j<=1; j++){
				for(int k=-1; k<=1; k++){
					int rr = r + j, cc = c + k;
					if(rr < 0 || rr >= N || cc < 0 || cc >= N || map[rr][cc] == '1') possible = false;
				}
			}
			if(possible && !visited[r][c][!x]){
				visited[r][c][!x] = true;
				Q.push(Node(r, c, !x));
			}
		}
	}
	puts("0");
}