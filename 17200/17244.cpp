#include <cstdio>
#include <cctype>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int MAX = 50;
const int MAX_I = 5;
const int MAX_B = 1<<MAX_I;

int main(){
	int R, C, sr, sc, er, ec, K = 0;
	char map[MAX][MAX];
	scanf("%d %d", &C, &R);
	for(int i = 0; i < R; ++i){
		getchar();
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == 'S'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'E'){
				er = i;
				ec = j;
			}
			else if(map[i][j] == 'X'){
				map[i][j] = '0' + (K++);
			}
		}
	}

	queue<int> Q;
	Q.push(sr*MAX + sc);
	bool visited[MAX][MAX][MAX_B] = {false,};
	visited[sr][sc][0] = true;
	int eb = (1<<K)-1;
	for(int result = 0; ; ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			int b = Q.front() / (MAX*MAX);
			int r = Q.front() % (MAX*MAX) / MAX;
			int c = Q.front() % MAX;
			Q.pop();
			if(r == er && c == ec && b == eb){
				printf("%d\n", result);
				return 0;
			}

			for(int d = 0; d < 4; ++d){
				int nr = r+roff[d], nc = c+coff[d], nb = b;
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
				if(isdigit(map[nr][nc])) nb |= 1<<(map[nr][nc]-'0');
				if(!visited[nr][nc][nb]){
					visited[nr][nc][nb] = true;
					Q.push(nb*MAX*MAX + nr*MAX + nc);
				}
			}
		}
	}
}