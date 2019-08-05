#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5;
const int INF = 1e9;

inline int calc(int a, int b, char op){
	if(op == '+') return a+b;
	if(op == '-') return a-b;
	return a*b;
}

inline bool isOp(char c){ return !(c >= '0' && c <= '9'); }

int N, rpos[MAX*2], cpos[MAX*2], r1 = -INF, r2 = INF;
char map[MAX][MAX];

void dfs(int r, int c, int k){
	if(r == N-1 && c == N-1){
		int val = map[0][0]-'0';
		for(int i = 0; i < N/2*2; ++i)
			val = calc(val, map[rpos[i*2+2]][cpos[i*2+2]]-'0', map[rpos[i*2+1]][cpos[i*2+1]]);
		r1 = max(val, r1);
		r2 = min(val, r2);
		return;
	}
	if(r < N-1 && isOp(map[r+1][c]) == k%2){
		rpos[k] = r+1;
		cpos[k] = c;
		dfs(r+1, c, k+1);
	}
	if(c < N-1 && isOp(map[r][c+1]) == k%2){
		rpos[k] = r;
		cpos[k] = c+1;
		dfs(r, c+1, k+1);
	}
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			scanf(" %c", &map[i][j]);
	dfs(0, 0, 1);
	printf("%d %d\n", r1, r2);
}