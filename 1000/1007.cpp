#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int N, x[20], y[20], xPlus, yPlus, xMinus, yMinus;
long long result;

inline long long d2(int x, int y){ return 1LL*x*x + 1LL*y*y; }

void dfs(int pos, int m){
	if(pos == N){
		long long temp = d2(xPlus-xMinus, yPlus-yMinus);
		if(result < 0 || result > temp) result = temp;
		return;
	}
	if(pos-m < N/2){
		xPlus += x[pos]; yPlus += y[pos];
		dfs(pos+1, m);
		xPlus -= x[pos]; yPlus -= y[pos];
	}
	if(m < N/2){
		xMinus += x[pos]; yMinus += y[pos];
		dfs(pos+1, m+1);
		xMinus -= x[pos]; yMinus -= y[pos];
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%d %d", x+i, y+i);
		result = -1;
		dfs(0, 0);
		printf("%.6lf\n", sqrt(result));
	}
}