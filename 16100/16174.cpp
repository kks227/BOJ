#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 64;
const int roff[2] = {1, 0};
const int coff[2] = {0, 1};

int main(){
	int N, map[MAX][MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%d", &map[i][j]);

	bool visited[MAX][MAX] = {true,};
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
		if(map[r][c] < 0) continue;
		for(int d = 0; d < 2; ++d){
			int nr = r+roff[d]*map[r][c], nc = c+coff[d]*map[r][c];
			if(nr >= N || nc >= N) continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*MAX + nc);
			}
		}
	}
	puts(visited[N-1][N-1] ? "HaruHaru" : "Hing");
}