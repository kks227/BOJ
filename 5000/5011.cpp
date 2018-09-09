#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
const unsigned int MOD = (1<<31)-1;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N;
	char map[1000][1000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			map[i][j] = getchar();
	}
	bool visited[1000][1000] = {true,};
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int r = Q.front()/1000, c = Q.front()%1000;
		Q.pop();
		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == '#') continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*1000 + nc);
			}
		}
	}
	if(!visited[N-1][N-1]){
		puts("INCONCEIVABLE");
		return 0;
	}

	unsigned int cnt[1000][1000] = {1,};
	memset(visited, 0, sizeof(visited));
	visited[0][0] = true;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(!visited[i][j]) continue;
			if(i < N-1 && map[i+1][j] == '.'){
				cnt[i+1][j] = (cnt[i][j] + cnt[i+1][j]) % MOD;
				visited[i+1][j] = true;
			}
			if(j < N-1 && map[i][j+1] == '.'){
				cnt[i][j+1] = (cnt[i][j] + cnt[i][j+1]) % MOD;
				visited[i][j+1] = true;
			}
		}
	}
	if(visited[N-1][N-1]) printf("%d\n", cnt[N-1][N-1]);
	else puts("THE GAME IS A LIE");
}