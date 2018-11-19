#include <cstdio>
using namespace std;

int main(){
	int R, C, Q, rSum[1001][1001] = {0};
	scanf("%d %d %d", &R, &C, &Q);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int val;
			scanf("%d", &val);
			rSum[i+1][j+1] = rSum[i+1][j] + rSum[i][j+1] - rSum[i][j] + val;
		}
	}

	for(int i = 0; i < Q; ++i){
		int r1, c1, r2, c2;
		scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
		--r1; --c1;
		int sum = rSum[r2][c2] - rSum[r2][c1] - rSum[r1][c2] + rSum[r1][c1];
		int size = (r2-r1)*(c2-c1);
		printf("%d\n", sum/size);
	}
}