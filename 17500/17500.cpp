#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 4;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N;
char map[MAX][MAX], rMap[MAX*5][MAX*5];
bool used[MAX*2+1][MAX*2+1];

bool dfs(int r, int c){
	if(r == N*2 && c == N*2){
		bool visited[MAX*2+1][MAX*2+1] = {false,};
		for(int i = 1; i < N*2; i += 2){
			for(int j = 1; j < N*2; j += 2){
				if(visited[i][j]) continue;
				visited[i][j] = true;
				queue<int> Q;
				Q.push(i*10 + j);
				int temp = -1;
				while(!Q.empty()){
					int r = Q.front()/10, c = Q.front()%10;
					Q.pop();
					if(r%2 && c%2 && map[r/2][c/2] != '.'){
						int k = map[r/2][c/2] - 'A';
						if(temp >= 0 && temp != k) return false;
						temp = k;
					}
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr > N*2 || nc < 0 || nc > N*2 || used[nr][nc]) continue;
						if(!visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*10 + nc);
						}
					}
				}
			}
		}
		return true;
	}

	for(int d = 0; d < 4; ++d){
		int nr0 = r+roff[d], nc0 = c+coff[d], nr = r+roff[d]*2, nc = c+coff[d]*2;
		if(nr < 0 || nr > N*2 || nc < 0 || nc > N*2 || used[nr][nc]) continue;
		used[nr0][nc0] = true;
		used[nr][nc] = true;
		if(d < 2) rMap[nr0+1][c*2+1] = '|';
		else{
			rMap[r+1][nc0*2] = '-';
			rMap[r+1][nc0*2+1] = '-';
			rMap[r+1][nc0*2+2] = '-';
		}
		
		if(dfs(nr, nc)) return true;

		used[nr0][nc0] = false;
		used[nr][nc] = false;
		if(d < 2) rMap[nr0+1][c*2+1] = ' ';
		else{
			rMap[r+1][nc0*2] = ' ';
			rMap[r+1][nc0*2+1] = ' ';
			rMap[r+1][nc0*2+2] = ' ';
		}
	}
	return false;
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N*2+3; ++i)
		fill(rMap[i], rMap[i]+(N*4+3), ' ');
	for(int i = 0; i < N*4+3; ++i)
		rMap[0][i] = rMap[N*2+2][i] = '#';
	for(int i = 0; i < N*2+3; ++i)
		rMap[i][0] = rMap[i][N*4+2] = '#';
	for(int i = 0; i <= N; ++i)
		for(int j = 0; j <= N; ++j)
			rMap[i*2+1][j*4+1] = '+';
	for(int i = 0; i < N; ++i){
		getchar();
		for(int j = 0; j < N; ++j)
			rMap[i*2+2][j*4+3] = map[i][j] = getchar();
	}
	used[0][0] = true;
	if(dfs(0, 0)){
		puts("yes");
		for(int i = 0; i < N*2+3; ++i)
			puts(rMap[i]);
	}
	else puts("no");
}