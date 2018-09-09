#include <cstdio>
#include <queue>
#include <cctype>
#include <algorithm>
#include <unordered_map>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	unordered_map<int, int> C2I;
	C2I['r'-'a'] = 0;
	C2I['g'-'a'] = 1;
	C2I['b'-'a'] = 2;
	C2I['y'-'a'] = 3;

	while(1){
		int R, C, sr, sc;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		char map[100][100];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == '*'){
					sr = i;
					sc = j;
				}
			}
		}

		queue<int> Q;
		Q.push(sr*100 + sc);
		int result = -1;
		bool visited[100][100][16] = {0};
		visited[sr][sc][0] = true;
		for(int k=0; !Q.empty(); k++){
			int qSize = Q.size();
			bool flag = false;
			for(int i=0; i<qSize; i++){
				int r = Q.front()%10000/100, c = Q.front()%100, keys = Q.front()/10000;
				Q.pop();
				if(map[r][c] == 'X') flag = true;
				else if(islower(map[r][c])){
					int kn = C2I[map[r][c]-'a'];
					keys |= 1<<kn;
				}
				else if(isupper(map[r][c])){
					int kn = C2I[map[r][c]-'A'];
					if(!(keys & 1<<kn)) continue;
				}

				for(int d=0; d<4; d++){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
					if(!visited[nr][nc][keys]){
						visited[nr][nc][keys] = true;
						Q.push(keys*10000 + nr*100 + nc);
					}
				}
			}
			if(flag){
				result = k;
				break;
			}
		}

		if(result >= 0) printf("Escape possible in %d steps.\n", result);
		else puts("The poor student is trapped!");
	}
}