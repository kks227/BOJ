#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int main(){
	int N, M;
	vector<int> s[100][100];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int x, y, a, b;
		scanf("%d %d %d %d", &x, &y, &a, &b);
		s[y-1][x-1].push_back((b-1)*100 + a-1);
	}

	int result = 1;
	bool visited[100][100] = {0}, lighted[100][100] = {0};
	queue<int> Q;
	visited[0][0] = lighted[0][0] = true;
	Q.push(0);
	while(!Q.empty()){
		int r = Q.front()/100, c = Q.front()%100;
		Q.pop();

		for(int v: s[r][c]){
			int nr = v/100, nc = v%100;
			if(visited[nr][nc] || lighted[nr][nc]) continue;
			lighted[nr][nc] = true;
			result++;

			bool flag = false;
			for(int d=0; d<4; d++){
				int nnr = nr+roff[d], nnc = nc+coff[d];
				if(nnr >=0 && nnr < N && nnc >= 0 && nnc < N && visited[nnr][nnc]){
					flag = true;
					break;
				}
			}
			if(flag){
				visited[nr][nc] = true;
				Q.push(nr*100 + nc);
			}
		}

		for(int d=0; d<4; d++){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || !lighted[nr][nc]) continue;
			visited[nr][nc] = true;
			Q.push(nr*100 + nc);
		}
	}
	printf("%d\n", result);
}