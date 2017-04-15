#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int INF = 1e9;
typedef pair<int, int> P;

int main(){
	int R, C, sr, sc, dr, dc;
	char map[50][50];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++){
			map[i][j] = getchar();
			if(map[i][j] == 'S'){
				sr = i;
				sc = j;
			}
			else if(map[i][j] == 'F'){
				dr = i;
				dc = j;
			}
		}
	}

	bool visited[50][50] = {0};
	int dist[50][50];
	for(int i=0; i<R; i++)
		fill(dist[i], dist[i]+C, INF);
	dist[sr][sc] = 0;
	priority_queue<P, vector<P>, greater<P>> PQ;
	PQ.push({0, sr*100+sc});
	while(!PQ.empty()){
		int r, c;
		do{
			r = PQ.top().second / 100;
			c = PQ.top().second % 100;
			PQ.pop();
		}while(!PQ.empty() && visited[r][c]);
		if(map[r][c] == 'F') break;

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
			int nd = dist[r][c];
			if(map[nr][nc] == 'g') nd += 10000;
			if(nd/10000 >= R*C) continue;
			for(int dd=0; dd<4; dd++){
				int rr = nr+roff[dd], cc = nc+coff[dd];
				if(rr < 0 || rr >= R || cc < 0 || cc >= C) continue;
				if(map[rr][cc] == 'g'){
					if(map[nr][nc] == '.') nd++;
					break;
				}
			}
			if(nd%10000 >= R*C) continue;
			if(dist[nr][nc] > nd){
				dist[nr][nc] = nd;
				PQ.push({dist[nr][nc], nr*100+nc});
			}
		}
	}
	printf("%d %d\n", dist[dr][dc]/10000, dist[dr][dc]%10000);
}