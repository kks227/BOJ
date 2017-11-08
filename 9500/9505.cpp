#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
#include <algorithm>
using namespace std;
const long long INF = 1e18;
typedef pair<long long, int> P;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int K, R, C, cost[26] = {0};
		scanf("%d %d %d", &K, &C, &R);
		for(int i=0; i<K; i++){
			char ch;
			int val;
			scanf(" %c %d", &ch, &val);
			cost[ch-'A'] = val;
		}
		int sr, sc;
		char map[1002][1002] = {0};
		for(int i=1; i<=R; i++){
			getchar();
			for(int j=1; j<=C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'E'){
					sr = i;
					sc = j;
				}
			}
		}

		long long dist[1002][1002];
		for(int i=0; i<=R+1; i++)
			fill(dist[i], dist[i]+C+2, INF);
		dist[sr][sc] = 0;
		priority_queue<P, vector<P>, greater<P>> PQ;
		bool visited[1002][1002] = {0};
		PQ.push(P(0, sr*1002+sc));
		while(!PQ.empty()){
			int r, c;
			do{
				r = PQ.top().second/1002;
				c = PQ.top().second%1002;
				PQ.pop();
			}while(!PQ.empty() && visited[r][c]);
			if(visited[r][c]) break;

			visited[r][c] = true;
			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d], nd = 0;
				if(nr < 0 || nr > R+1 || nc < 0 || nc > C+1 || visited[nr][nc]) continue;
				if(map[nr][nc]) nd = cost[map[nr][nc]-'A'];
				if(dist[nr][nc] > dist[r][c] + nd){
					dist[nr][nc] = dist[r][c] + nd;
					PQ.push(P(dist[nr][nc], nr*1002+nc));
				}
			}
		}
		printf("%lld\n", dist[0][0]);
	}
}