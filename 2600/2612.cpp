#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000;
const int UNDEF = -1e9;

int M, N, dp[MAX+1][MAX+1];
char A[MAX+1], B[MAX+1], X[MAX+1], Y[MAX+1];

int DNA(int a, int b){
	int &ret = dp[a][b];
	if(ret != UNDEF) return ret;
	if(a == M || b == N) return ret = 0;

	ret = max(DNA(a+1, b+1) + (A[a] == B[b] ? 3 : -2), 0);
	ret = max(DNA(a+1, b) - 2, ret);
	ret = max(DNA(a, b+1) - 2, ret);
	return ret;
}

void trace(int a, int b, int x, int y){
	if(DNA(a, b) == 0) return;

	if(DNA(a, b) == DNA(a+1, b+1) + (A[a] == B[b] ? 3 : -2)){
		X[x] = A[a];
		Y[y] = B[b];
		trace(a+1, b+1, x+1, y+1);
	}
	else if(DNA(a, b) == DNA(a+1, b) - 2){
		X[x] = A[a];
		trace(a+1, b, x+1, y);
	}
	else if(DNA(a, b) == DNA(a, b+1) - 2){
		Y[y] = B[b];
		trace(a, b+1, x, y+1);
	}
}

int main(){
	scanf("%d %s %d %s", &M, A, &N, B);
	for(int i = 0; i <= M; ++i)
		fill(dp[i], dp[i]+N+1, UNDEF);

	int result = UNDEF, a = -1, b = -1;
	for(int i = 0; i < M; ++i){
		for(int j = 0; j < N; ++j){
			if(A[i] != B[j]) continue;
			int temp = DNA(i, j);
			if(result < temp){
				result = temp;
				a = i;
				b = j;
			}
		}
	}
	printf("%d\n", result);
	trace(a, b, 0, 0);
	printf("%s\n%s\n", X, Y);
}