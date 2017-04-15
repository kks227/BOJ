#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <functional>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};
const char dirc[2][4] = {'n', 'e', 's', 'w', 'N', 'E', 'S', 'W'};
const int INF = 1e9;
typedef tuple<int, int, int, int> Node;
typedef pair<int, Node> P;

int main(){
	for(int t=1; ; t++){
		int R, C;
		scanf("%d %d", &R, &C);
		if(R == 0) break;

		int sr, sc, sbr, sbc, dr, dc;
		char map[20][20];
		for(int i=0; i<R; i++){
			getchar();
			for(int j=0; j<C; j++){
				map[i][j] = getchar();
				if(map[i][j] == 'S'){
					sr = i;
					sc = j;
				}
				else if(map[i][j] == 'B'){
					sbr = i;
					sbc = j;
				}
				else if(map[i][j] == 'T'){
					dr = i;
					dc = j;
				}
			}
		}

		int dist[20][20][20][20], r, c, br, bc;
		for(int i=0; i<R; i++)
			for(int j=0; j<C; j++)
				for(int k=0; k<R; k++)
					for(int l=0; l<C; l++)
						dist[i][j][k][l] = INF;
		dist[sr][sc][sbr][sbc] = 0;
		bool visited[20][20][20][20] = {0};
		char path[20][20][20][20] = {0};
		Node prev[20][20][20][20];
		priority_queue<P, vector<P>, greater<P>> PQ;
		PQ.push(P(0, Node(sr, sc, sbr, sbc)));

		while(!PQ.empty()){
			do{
				tie<int, int, int, int>(r, c, br, bc) = PQ.top().second;
				PQ.pop();
			}while(!PQ.empty() && visited[r][c][br][bc]);
			if(visited[r][c][br][bc]) break;
			visited[r][c][br][bc] = true;
			if(br == dr && bc == dc) break;

			for(int d=0; d<4; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] == '#') continue;
				int nbr = br, nbc = bc;
				bool pushed = false;
				if(nr == br && nc == bc){
					nbr += roff[d];
					nbc += coff[d];
					pushed = true;
				}
				if(nbr < 0 || nbr >= R || nbc < 0 || nbc >= C || map[nbr][nbc] == '#') continue;

				int newDist = dist[r][c][br][bc] + (pushed ? 10000 : 1);
				if(dist[nr][nc][nbr][nbc] > newDist){
					dist[nr][nc][nbr][nbc] = newDist;
					path[nr][nc][nbr][nbc] = dirc[pushed][d];
					prev[nr][nc][nbr][nbc] = Node(r, c, br, bc);
					PQ.push(P(newDist, Node(nr, nc, nbr, nbc)));
				}
			}
		}

		printf("Maze #%d\n", t);
		if(br == dr && bc == dc){
			vector<char> result;
			while(r != sr || c != sc || br != sbr || bc != sbc){
				result.push_back(path[r][c][br][bc]);
				tie<int, int, int, int>(r, c, br, bc) = prev[r][c][br][bc];
			}
			for(int i=result.size()-1; i>=0; i--)
				putchar(result[i]);
			puts("");
		}
		else puts("Impossible.");
		puts("");
	}
}