#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int MAX = 12;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<string, bool> Node;

bool isStable(int R, int C, int K, char map[MAX][MAX]){
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			if(map[i][j] == 'o'){
				bool visited[MAX][MAX] = {false,};
				queue<int> Q;
				visited[i][j] = true;
				Q.push(i*MAX + j);
				int cnt = 0;
				while(!Q.empty()){
					int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
					++cnt;
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'o') continue;
						if(!visited[nr][nc]){
							visited[nr][nc] = true;
							Q.push(nr*MAX + nc);
						}
					}
				}
				return (cnt == K);
			}
		}
	}
	return true; // dummy
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int R, C, K = 0;
		bool goal[MAX][MAX] = {false,};
		char map[MAX][MAX];
		Node s("", true);
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				if(map[i][j] == 'x' || map[i][j] == 'w'){
					goal[i][j] = true;
					++K;
				}
				if(map[i][j] == 'o' || map[i][j] == 'w'){
					s.first.push_back(i);
					s.first.push_back(j);
				}
				if(map[i][j] != '#') map[i][j] = '.';
			}
		}

		queue<Node> Q;
		unordered_set<string> visited;
		Q.push(s);
		visited.insert(s.first);
		int result = -1;
		for(int i = 0; !Q.empty() && result == -1; ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				string curr = Q.front().first;
				bool currStable = Q.front().second;
				Q.pop();
				bool flag = true;
				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					map[r][c] = 'o';
					if(!goal[r][c]) flag = false;
				}
				if(flag){
					result = i;
					break;
				}

				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d], pr = r-roff[d], pc = c-coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != '.') continue;
						if(pr < 0 || pr >= R || pc < 0 || pc >= C || map[pr][pc] != '.') continue;
						string next(curr);
						next[k*2] = nr; next[k*2+1] = nc;
						if(visited.find(next) != visited.end()) continue;

						swap(map[r][c], map[nr][nc]);
						bool nextStable = isStable(R, C, K, map);
						if(currStable || nextStable){
							Q.push(Node(next, nextStable));
							visited.insert(next);
						}
						swap(map[r][c], map[nr][nc]);
					}
				}

				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					map[r][c] = '.';
				}
			}
		}
		printf("Case #%d: %d\n", t, result);
	}
}