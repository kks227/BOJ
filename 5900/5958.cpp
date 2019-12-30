#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 1000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N;
	char map[MAX][MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		getchar();
		for(int j = 0; j < N; ++j)
			map[i][j] = getchar();
	}

	int result = 0;
	bool visited[MAX][MAX] = {false,};
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			if(map[i][j] == '.' || visited[i][j]) continue;

			queue<int> Q;
			Q.push(i*MAX + j);
			visited[i][j] = true;
			while(!Q.empty()){
				int r = Q.front() / MAX, c = Q.front() % MAX;
				Q.pop();
				for(int d = 0; d < 4; ++d){
					int nr = r + roff[d], nc = c + coff[d];
					if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == '.') continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(nr*MAX + nc);
					}
				}
			}
			++result;
		}
	}
	printf("%d\n", result);
}