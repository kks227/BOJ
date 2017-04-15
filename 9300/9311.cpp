#include <cstdio>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
typedef tuple<int, int> Node;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, sr, sc;
		scanf("%d %d", &R, &C);
		vector<vector<char>> map(R, vector<char>(C));
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'S'){
					sr = i;
					sc = j;
				}
			}
		}

		vector<vector<bool>> visited(R, vector<bool>(C, false));
		visited[sr][sc] = true;
		queue<Node> Q;
		Q.push(Node(sr, sc));
		bool success = false;
		for(int result=0; !Q.empty(); result++){
			int qSize = Q.size();
			for(int i=0; i<qSize; i++){
				int r, c;
				tie<int, int>(r, c) = Q.front();
				Q.pop();
				if(map[r][c] == 'G'){
					success = true;
					printf("Shortest Path: %d\n", result);
					break;
				}

				for(int d=0; d<4; d++){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == 'X') continue;
					if(!visited[nr][nc]){
						visited[nr][nc] = true;
						Q.push(Node(nr, nc));
					}
				}
			}
			if(success) break;
		}
		if(!success) puts("No Exit");
	}
}