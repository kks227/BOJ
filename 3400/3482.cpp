#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, sr = -1, sc;
		scanf("%d %d", &C, &R);
		bool map[1000][1000];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++)
				map[i][j] = (getchar() == '#');
		}
		for(int i=1; i<R-1; i++){
			for(int j=1; j<C-1; j++){
				if(map[i][j]) continue;

				int cnt = 0;
				for(int d=0; d<4; d++){
					int nr = i+roff[d], nc = j+coff[d];
					if(!map[nr][nc]) cnt++;
				}
				if(cnt <= 1){
					sr = i;
					sc = j;
					break;
				}
			}
			if(sr >= 0) break;
		}

		for(int k=0; k<2; k++){
			bool visited[1000][1000] = {0};
			int dist[1000][1000];
			queue<int> Q;
			visited[sr][sc] = true;
			for(int i=0; i<R; i++)
				fill(dist[i], dist[i]+C, INF);
			dist[sr][sc] = 0;
			Q.push(sr*1000+sc);

			int result;
			for(result=0; !Q.empty(); result++){
				int qSize = Q.size();
				for(int i=0; i<qSize; i++){
					int r = Q.front()/1000, c = Q.front()%1000;
					Q.pop();
					for(int d=0; d<4; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(map[nr][nc] || visited[nr][nc]) continue;
						visited[nr][nc] = true;
						dist[nr][nc] = result+1;
						sr = nr;
						sc = nc;
						Q.push(nr*1000+nc);
					}
				}
			}
			if(k) printf("Maximum rope length is %d.\n", result-1);
		}
	}
}