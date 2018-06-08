#include <cstdio>
#include <queue>
using namespace std;
const int roff[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int coff[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main(){
	int N, M, K, T;
	scanf("%d %d %d %d", &N, &M, &K, &T);
	bool visited[2][300][300] = {0};
	queue<int> Q;
	for(int i=0; i<M; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		visited[0][--r][--c] = true;
		Q.push(r*300 + c);
	}
	bool turn = false;
	for(int t=0; t<T; t++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int r = Q.front()/300, c = Q.front()%300;
			Q.pop();
			for(int d=0; d<8; d++){
				int nr = r+roff[d], nc = c+coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
				if(!visited[!turn][nr][nc]){
					visited[!turn][nr][nc] = true;
					Q.push(nr*300 + nc);
				}
			}
		}
		turn = !turn;
	}

	bool result = false;
	for(int i=0; i<K; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		if(visited[turn][--r][--c]) result = true;
	}
	puts(result ? "YES" : "NO");
}