#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef vector<vector<int>> Map;

int R, C;

int dfs(int k, Map &map){
	int result = 0;
	vector<vector<bool>> visited(R, vector<bool>(C));
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			if(!visited[i][j] && map[i][j] > 0){
				Map nmap = map;
				int temp = 0;
				queue<int> Q;
				visited[i][j] = true;
				Q.push(i*10 + j);
				while(!Q.empty()){
					int r = Q.front()/10, c = Q.front()%10; Q.pop();
					nmap[r][c] = 0;
					temp++;
					for(int d=0; d<4; d++){
						int nr = r+roff[d], nc = c+coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || map[r][c] != map[nr][nc]) continue;
						visited[nr][nc] = true;
						Q.push(nr*10 + nc);
					}
				}

				for(int j=0; j<C; j++){
					for(int i=R-1; i>=0; i--){
						if(nmap[i][j] > 0) continue;
						int k = i-1;
						for(; k>=0 && nmap[k][j]==0; k--);
						if(k >= 0) swap(nmap[i][j], nmap[k][j]);
					}
				}
				result = max(temp*temp + (k>1 ? dfs(k-1, nmap) : 0), result);
			}
		}
	}
	return result;
}

int main(){
	scanf("%d %d", &C, &R);
	Map map(R, vector<int>(C));
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%d", &map[i][j]);
	printf("%d\n", dfs(3, map));
}