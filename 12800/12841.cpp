#include <cstdio>
using namespace std;
const int MAX = 100000;

int main(){
	int N, d[MAX];
	long long pSum[2][MAX] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", d+i);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < N-1; ++j){
			int val;
			scanf("%d", &val);
			pSum[i][j+1] = pSum[i][j] + val;
		}
	}
	long long r1 = pSum[0][N-1] + d[N-1];
	int r2 = N;
	for(int i = 0; i < N-1; ++i){
		long long temp = pSum[0][i] + d[i] + pSum[1][N-1]-pSum[1][i];
		if(r1 >= temp){
			r1 = temp;
			r2 = i+1;
		}
	}
	printf("%d %lld\n", r2, r1);
}