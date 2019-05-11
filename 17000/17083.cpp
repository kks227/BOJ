#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;
const int MAX = MAX_N*MAX_N;
const int INF = 1e9;
const char mark[5] = {'Y', 'O', 'N', 'S', 'E'};

int main(){
	int R, C, K[2] = {0,}, r[2][MAX], c[2][MAX], num[MAX_N][MAX_N];
	bool type[MAX_N][MAX_N] = {false,};
	char map[MAX_N][MAX_N];
	scanf("%d %d\n", &R, &C);
	memset(num, -1, sizeof(num));
	vector<int> adj[2][MAX];
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			map[i][j] = getchar();
			if(map[i][j] == '1'){
				r[0][K[0]] = i;
				c[0][K[0]] = j;
				num[i][j] = K[0]++;
			}
			else if(map[i][j] == '2'){
				r[1][K[1]] = i;
				c[1][K[1]] = j;
				num[i][j] = K[1]++;
				type[i][j] = true;
			}
		}
		getchar();
	}

	int need[2] = {0,}, s = 0;
	for(int k = 0; k < 2; ++k){
		char cc = '1' + k;
		bool nodeFlag = false, edgeFlag = false;
		for(int i = 0; i < R; ++i){
			int pos = -1;
			for(int j = 0; j < C; ++j){
				if(map[i][j] == cc){
					nodeFlag = true;
					if(pos >= 0){
						int u = num[i][pos], v = num[i][j];
						adj[k][u].push_back(v);
						adj[k][v].push_back(u);
						edgeFlag = true;
					}
					pos = j;
				}
				else if(map[i][j] != '.') pos = -1;
			}
		}
		for(int j = 0; j < C; ++j){
			int pos = -1;
			for(int i = 0; i < R; ++i){
				if(map[i][j] == cc){
					nodeFlag = true;
					if(pos >= 0){
						int u = num[pos][j], v = num[i][j];
						adj[k][u].push_back(v);
						adj[k][v].push_back(u);
						edgeFlag = true;
					}
					pos = i;
				}
				else if(map[i][j] != '.') pos = -1;
			}
		}
		if(!nodeFlag){
			need[k] = 0;
			continue;
		}
		if(!edgeFlag){
			need[k] = 1;
			for(int i = 0; i < K[k]; ++i)
				map[ r[k][i] ][ c[k][i] ] = mark[s];
			++s;
			continue;
		}

		queue<int> Q;
		int dist[MAX];
		fill(dist, dist+K[k], INF);
		need[k] = 2;
		for(int i = 0; i < K[k]; ++i){
			if(dist[i] != INF) continue;

			dist[i] = 0;
			Q.push(i);
			bool breakFlag = false;
			for(int j = 0; !Q.empty(); ++j){
				int qSize = Q.size();
				for(int l = 0; l < qSize; ++l){
					int curr = Q.front(); Q.pop();
					for(int next: adj[k][curr]){
						if(dist[next] == INF){
							dist[next] = dist[curr]+1;
							Q.push(next);
						}
						else if(dist[next] == dist[curr]){
							breakFlag = true;
							break;
						}
					}
					if(breakFlag) break;
				}
				if(breakFlag) break;
			}
			if(breakFlag){
				need[k] = 3;
				break;
			}
		}

		if(need[k] == 2){
			for(int i = 0; i < K[k]; ++i)
				map[ r[k][i] ][ c[k][i] ] = mark[ s + dist[i]%2 ];
		}
		else{
			int color[MAX_N][MAX_N];
			memset(color, -1, sizeof(color));
			for(int i = 0; i < R; ++i){
				for(int j = 0; j < C; ++j){
					if(map[i][j] != cc) continue;

					int u = -1, v = -1;
					for(int h = i-1; h >= 0; --h){
						if(map[h][j] == '#') break;
						if(map[h][j] == '.') continue;
						if(type[h][j] == k) u = color[h][j];
						break;
					}
					for(int h = j-1; h >= 0; --h){
						if(map[i][h] == '#') break;
						if(map[i][h] == '.') continue;
						if(type[i][h] == k) v = color[i][h];
						break;
					}

					int w = 0;
					for(; w == u || w == v; ++w);
					color[i][j] = w;
					map[i][j] = mark[s+w];
				}
			}
		}

		s += need[k];
	}

	if(need[0] + need[1] > 5) puts("NO");
	else{
		puts("YES");
		for(int i = 0; i < R; ++i){
			for(int j = 0; j < C; ++j)
				putchar(map[i][j]);
			puts("");
		}
	}
}