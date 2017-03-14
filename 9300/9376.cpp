#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e8;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct Node{
	int r, c, d;
	Node(): Node(0, 0, 0){}
	Node(int r1, int c1, int d1): r(r1), c(c1), d(d1){}
	bool operator <(const Node& O)const{ return d > O.d; }
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int H, W, sr[3] = {0}, sc[3] = {0}, jcnt = 0, d[3][102][102];
		char map[102][102];
		scanf("%d %d", &H, &W);
		fill(map[0], map[0]+W+2, '.');
		fill(map[H+1], map[H+1]+W+2, '.');
		for(int i=1; i<=H; i++){
			map[i][0] = map[i][W+1] = '.';
			getchar();
			for(int j=1; j<=W; j++){
				map[i][j] = getchar();
				if(map[i][j] == '$'){
					sr[jcnt] = i;
					sc[jcnt] = j;
					jcnt++;
				}
			}
		}

		for(int k=0; k<3; k++){
			priority_queue<Node> PQ;
			for(int i=0; i<H+2; i++)
				for(int j=0; j<W+2; j++)
					d[k][i][j] = INF;
			PQ.push(Node(sr[k], sc[k], 0));
			d[k][sr[k]][sc[k]] = 0;
			bool visited[102][102] = {0};

			while(!PQ.empty()){
				int r, c;
				do{
					r = PQ.top().r;
					c = PQ.top().c;
					PQ.pop();
				}while(visited[r][c]);
				if(visited[r][c]) break;

				visited[r][c] = true;
				for(int l=0; l<4; l++){
					int nr = r+roff[l], nc = c+coff[l];
					if(nr<0 || nr>H+1 || nc<0 || nc>W+1 || visited[nr][nc] || map[nr][nc] == '*') continue;
					int nd = d[k][r][c] + (map[nr][nc] == '#');
					if(d[k][nr][nc] > nd){
						d[k][nr][nc] = nd;
						PQ.push(Node(nr, nc, nd));
					}
				}
			}
		}

		int result = INF;
		for(int i=1; i<=H; i++)
			for(int j=1; j<=W; j++)
				if(map[i][j] != '*')
					result = min(result, d[0][i][j]+d[1][i][j]+d[2][i][j]-2*(map[i][j] == '#'));
		printf("%d\n", result);
	}
}