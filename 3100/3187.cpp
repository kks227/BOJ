#include <cstdio>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int R, C;
	char map[250][250];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}

	int result[2] = {0};
	bool visited[250][250] = {0};
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if((map[i][j] == 'v' || map[i][j] == 'k') && !visited[i][j]){
				visited[i][j] = true;
				queue<int> Q;
				Q.push(i*1000 + j);
				int cnt[2] = {0};
				while(!Q.empty()){
					int r = Q.front()/1000, c = Q.front()%1000; Q.pop();
					if(map[r][c] == 'v') cnt[1]++;
					else if(map[r][c] == 'k') cnt[0]++;
					for(int d=0; d<4; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(map[nr][nc] != '#' && !visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*1000 + nc);
						}
					}
				}
				if(cnt[0] > cnt[1]) result[0] += cnt[0];
				else result[1] += cnt[1];
			}
		}
	}
	printf("%d %d\n", result[0], result[1]);
}