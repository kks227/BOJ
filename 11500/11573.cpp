#include <cstdio>
using namespace std;
const int MAX = 100;

double dp[MAX+1][MAX+1][MAX+1][3];

double mob(int r, int g, int b, int k){
	double &ret = dp[r][g][b][k];
	if(ret != -1) return ret;
	int a[3] = {r, g, b};
	if(a[(k+2)%3] == 0) return ret = 1;
	if(a[(k+1)%3] == 0 || a[k] == 0) return ret = 0;

	ret = 0;
	int p = r*g + g*b + b*r;
	for(int i = 0; i < 3; ++i){
		int j = (i+1)%3, q = a[i]*a[j];
		--a[j];
		ret += 1.0*q/p * mob(a[0], a[1], a[2], k);
		++a[j];
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int i = 0; i <= MAX; ++i)
		for(int j = 0; j <= MAX; ++j)
			for(int k = 0; k <= MAX; ++k)
				for(int l = 0; l < 3; ++l)
					dp[i][j][k][l] = -1;
	for(int t = 0; t < T; ++t){
		int r, g, b;
		scanf("%d %d %d", &r, &g, &b);
		for(int k = 0; k < 3; ++k)
			printf("%.10f ", mob(r, g, b, k));
		puts("");
	}
}