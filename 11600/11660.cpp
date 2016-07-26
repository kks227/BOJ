#include <cstdio>
using namespace std;

int main(){
	int N, M, rSum[1025][1025] = {0};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int val;
			scanf("%d", &val);
			rSum[i+1][j+1] = rSum[i+1][j] + rSum[i][j+1] - rSum[i][j] + val;
		}
	}
	for(int i=0; i<M; i++){
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		printf("%d\n", rSum[x2][y2] - rSum[x1-1][y2] - rSum[x2][y1-1] + rSum[x1-1][y1-1]);
	}
}