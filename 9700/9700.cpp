#include <cstdio>
#include <queue>
using namespace std;
const int MAX = 40;
const int roff[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int coff[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	int N;
	for(int t = 1; scanf("%d", &N) > 0; ++t){
		bool map[MAX][MAX] = {false,}, visited[MAX][MAX] = {false,};
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				int k;
				scanf("%1d", &k);
				if(k) map[i][j] = true;
			}
		}

		int result = 0;
		for(int i = 0; i < N; ++i){
			for(int j = 0; j < N; ++j){
				if(!map[i][j] || visited[i][j]) continue;

				queue<int> Q;
				Q.push(i*MAX+j);
				visited[i][j] = true;
				while(!Q.empty()){
					int r = Q.front()/MAX, c = Q.front()%MAX;
					Q.pop();
					for(int d = 0; d < 8; ++d){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= N || nc < 0 || nc >= N || !map[nr][nc]) continue;
						if(!visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*MAX+nc);
						}
					}
				}
				++result;
			}
		}
		printf("Case #%d: %d\n", t, result);
	}
}