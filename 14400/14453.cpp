#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[100000], pSum[100001][3] = {0};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char c;
		scanf(" %c", &c);
		A[i] = (c == 'H' ? 0 : c == 'S' ? 1 : 2);
		for(int j = 0; j < 3; ++j)
			pSum[i+1][j] = pSum[i][j] + (A[i] == j);
	}
	int result = 0;
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 3; ++k)
				result = max(pSum[i][j] + pSum[N][k] - pSum[i][k], result);
	printf("%d\n", result);
}