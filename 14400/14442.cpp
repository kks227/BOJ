#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

struct Node{
	int r, c, k;
	Node(): Node(0, 0, 0){}
	Node(int r1, int c1, int k1): r(r1), c(c1), k(k1){}
};

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	bool map[1000][1000], visited[1000][1000][11] = {0};
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			scanf("%1d", &map[i][j]);

	queue<Node> Q;
	Q.push(Node(0, 0, 0));
	visited[0][0][0] = true;
	int result = 1;
	while(!Q.empty()){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front().r, c = Q.front().c, k = Q.front().k;
			Q.pop();
			if(r == N-1 && c == M-1){
				printf("%d\n", result);
				return 0;
			}
			for(int d=0; d<4; d++){
				int nr = r + roff[d], nc = c + coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
				int nk = k + map[nr][nc];
				if(nk > K || visited[nr][nc][nk]) continue;
				visited[nr][nc][nk] = true;
				Q.push(Node(nr, nc, nk));
			}
		}
		result++;
	}
	puts("-1");
}