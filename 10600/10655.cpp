#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100000;
const int INF = 2*1e9;

int main(){
	int N, x[MAX], y[MAX], pSum[MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", x+i, y+i);
		if(i > 0)
			pSum[i] = pSum[i-1] + abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]);
	}

	int result = INF;
	for(int i = 1; i < N-1; ++i)
		result = min(pSum[i-1] + pSum[N-1]-pSum[i+1] + abs(x[i+1]-x[i-1]) + abs(y[i+1]-y[i-1]), result);
	printf("%d\n", result);
}