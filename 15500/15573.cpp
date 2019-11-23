#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <functional>
using namespace std;
const int MAX = 1000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int R, C, K, S[MAX][MAX];
	bool visited[MAX][MAX] = {false,};
	priority_queue<P, vector<P>, greater<P>> PQ;
	scanf("%d %d %d", &R, &C, &K);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			scanf("%d", &S[i][j]);
			if(i == 0 || j == 0 || j == C-1){
				PQ.push(P(S[i][j], i*MAX+j));
				visited[i][j] = true;
			}
		}
	}
	int D = 0;
	for(int i = 0; i < K; ++i){
		int r = PQ.top().second / MAX, c = PQ.top().second % MAX;
		PQ.pop();
		D = max(D, S[r][c]);
		for(int d = 0; d < 4; ++d){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				PQ.push(P(S[nr][nc], nr*MAX+nc));
			}
		}
	}
	printf("%d\n", D);
}