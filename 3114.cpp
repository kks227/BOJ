#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1500][1500];
int map[1500][1500];
int apple_sum[1500][1500];
int banana_sum[1500][1500];
int R, C;

int bulldozer(int start_row, int start_col){
	int &ret = cache[start_row][start_col];
	if(ret != -1) return ret;
	if(start_row == R-1 || start_col == C-1) return ret = 0;

	int right = bulldozer(start_row, start_col+1);
	right += apple_sum[R-1][start_col];
	right -= apple_sum[start_row][start_col];

	int down = bulldozer(start_row+1, start_col);
	down += banana_sum[start_row][C-1];
	down -= banana_sum[start_row][start_col];

	int diagonal = bulldozer(start_row+1, start_col+1);
	diagonal += apple_sum[R-1][start_col];
	diagonal -= apple_sum[start_row][start_col];
	diagonal += banana_sum[start_row][C-1];
	diagonal -= banana_sum[start_row][start_col];

	ret = max(right, down);
	ret = max(ret, diagonal);
	return ret;
}

int main(){

	memset(cache, -1, sizeof(int)*1500*1500);
	cin >> R >> C;
	int n;
	char fruit;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			getchar();
			fruit = getchar();
			scanf("%d", &n);
			if(fruit=='A'){
				map[i][j] = -n;
				if(i==0) apple_sum[i][j] = n;
				else apple_sum[i][j] = apple_sum[i-1][j] + n;
				banana_sum[i][j] = (j==0) ? 0 : banana_sum[i][j-1];
			}
			else{
				map[i][j] = n;
				if(j==0) banana_sum[i][j] = n;
				else banana_sum[i][j] = banana_sum[i][j-1] + n;
				apple_sum[i][j] = (i==0) ? 0 : apple_sum[i-1][j];
			}
		}
	}
	cout << bulldozer(0, 0) << endl;

	return 0;
}