#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, H, N, dp[7][7][7][7][7][7];
bool raisin[7][7][7];

int cut(int r1, int c1, int h1, int r2, int c2, int h2, int n){
	int &ret = dp[r1][c1][h1][r2][c2][h2];
	if(ret != -1) return ret;
	if(n == 1) return ret = (r2-r1+1)*(c2-c1+1)*(h2-h1+1);

	ret = 0;
	for(int r=r1; r<r2; r++){
		int cnt = 0;
		for(int i=r1; i<=r; i++)
			for(int j=c1; j<=c2; j++)
				for(int k=h1; k<=h2; k++)
					cnt += raisin[i][j][k];
		if(0 < cnt && cnt < n)
			ret = max(ret, min(cut(r1, c1, h1, r, c2, h2, cnt), cut(r+1, c1, h1, r2, c2, h2, n-cnt)));
	}
	for(int c=c1; c<c2; c++){
		int cnt = 0;
		for(int i=r1; i<=r2; i++)
			for(int j=c1; j<=c; j++)
				for(int k=h1; k<=h2; k++)
					cnt += raisin[i][j][k];
		if(0 < cnt && cnt < n)
			ret = max(ret, min(cut(r1, c1, h1, r2, c, h2, cnt), cut(r1, c+1, h1, r2, c2, h2, n-cnt)));
	}
	for(int h=h1; h<h2; h++){
		int cnt = 0;
		for(int i=r1; i<=r2; i++)
			for(int j=c1; j<=c2; j++)
				for(int k=h1; k<=h; k++)
					cnt += raisin[i][j][k];
		if(0 < cnt && cnt < n)
			ret = max(ret, min(cut(r1, c1, h1, r2, c2, h, cnt), cut(r1, c1, h+1, r2, c2, h2, n-cnt)));
	}
	return ret;
}

int main(){
	scanf("%d %d %d %d", &R, &C, &H, &N);
	for(int i=0; i<N; i++){
		int r, c, h;
		scanf("%d %d %d", &r, &c, &h);
		raisin[r-1][c-1][h-1] = true;
	}
	memset(dp, -1, sizeof(dp));
	printf("%d\n", cut(0, 0, 0, R-1, C-1, H-1, N));
}