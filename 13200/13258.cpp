#include <cstdio>
using namespace std;

int A, B, J, W;
double dp[1001][1001];

double bank(int w, int a){
	double &ret = dp[w][a];
	if(ret >= 0) return ret;
	if(w == W) return ret = A + a*J;

	int p = A + a*J, q = B + (w-a)*J, r = p+q;
	return ret = bank(w+1, a+1)*p/r + bank(w+1, a)*q/r;
}

int main(){
	int N;
	scanf("%d %d", &N, &A);
	for(int i=1; i<N; i++){
		int val;
		scanf("%d", &val);
		B += val;
	}
	scanf("%d %d", &J, &W);
	for(int i=0; i<=W; i++)
		for(int j=0; j<=W; j++)
			dp[i][j] = -1;
	printf("%.10lf\n", bank(0, 0));
}