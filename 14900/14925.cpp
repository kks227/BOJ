#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int R, C, rSum[1001][1001] = {0}, map[1000][1000];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2) map[i][j] = 1;
			rSum[i+1][j+1] = rSum[i][j+1] + rSum[i+1][j] - rSum[i][j] + map[i][j];
		}
	}

	int lo = 0, hi = min(R, C)+1;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		bool flag = false;
		for(int i=0; i<=R-mid; i++){
			for(int j=0; j<=C-mid; j++){
				if(rSum[i+mid][j+mid]-rSum[i][j+mid]-rSum[i+mid][j]+rSum[i][j] == 0){
					flag = true;
					break;
				}
			}
			if(flag) break;
		}
		(flag ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}