#include <cstdio>
using namespace std;
const int xoff[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
const int yoff[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

int N;
double dp[50][50][51];

double knight(int x, int y, int k){
	double &ret = dp[x][y][k];
	if(ret >= 0) return ret;
	if(k == 0) return ret = 1;

	ret = 0;
	for(int d=0; d<8; d++){
		int nx = x+xoff[d], ny = y+yoff[d];
		if(nx >= 0 && nx < N && ny >= 0 && ny < N) ret += knight(nx, ny, k-1);
	}
	return ret /= 8;
}

int main(){
	int x, y, K;
	scanf("%d %d %d %d", &N, &x, &y, &K);
	x--; y--;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<=K; k++)
				dp[i][j][k] = -1;
	printf("%.10lf\n", knight(x, y, K));
}