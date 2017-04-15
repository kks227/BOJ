#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const int ropen[2][4] = {{1, 0, 1, 0}, {1, 0, 0, 1}};
const int copen[2][4] = {{1, 0, 0, 1}, {1, 0, 1, 0}};

typedef tuple<int, int, int, int> Node;

int main(){
	int N, M;
	char map[7][7];
	bool visited[7][7][1<<7][1<<7] = {1,};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<M; j++)
			map[i][j] = getchar()-'A';
	}

	queue<Node> Q;
	Q.push(Node(0, 0, 0, 0));
	for(int result=0; !Q.empty(); result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r, c, rb, cb;
			tie<int, int, int, int>(r, c, rb, cb) = Q.front();
			Q.pop();
			if(r == N-1 && c == M-1){
				printf("%d\n", result);
				return 0;
			}

			for(int d=0; d<4; d++){
				if(!(d<2 ? ropen : copen)[ !(rb&(1<<r)) != !(cb&(1<<c)) ][ map[r][c] ]) continue;
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				if(!(d<2 ? ropen : copen)[ !(rb&(1<<nr)) != !(cb&(1<<nc)) ][ map[nr][nc] ]) continue;
				if(visited[nr][nc][rb][cb]) continue;
				visited[nr][nc][rb][cb] = true;
				Q.push(Node(nr, nc, rb, cb));
			}
			int temp = rb & (1<<r);
			int nrb = rb - temp + (!temp)*(1<<r);
			temp = cb & (1<<c);
			int ncb = cb - temp + (!temp)*(1<<c);
			if(!visited[r][c][nrb][ncb]){
				visited[r][c][nrb][ncb] = true;
				Q.push(Node(r, c, nrb, ncb));
			}
		}
	}
	puts("-1");
}