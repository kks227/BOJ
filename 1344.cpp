#include <cstdio>
using namespace std;

bool isP[19] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0};
int A, B;
double dp[19][19][19];

double OptimusPrime(int s, int a, int b){
	double &ret = dp[s][a][b];
	if(ret != -1) return ret;
	if(s == 18) return isP[a] || isP[b];

	return ret = OptimusPrime(s+1, a+1, b+1) * A*B/10000 + OptimusPrime(s+1, a, b+1) * (100-A)*B/10000
		+ OptimusPrime(s+1, a+1, b) * A*(100-B)/10000 + OptimusPrime(s+1, a, b) * (100-A)*(100-B)/10000;
}

int main(){
	scanf("%d %d", &A, &B);
	for(int i=0; i<19; i++)
		for(int j=0; j<19; j++)
			for(int k=0; k<19; k++)
				dp[i][j][k] = -1;
	printf("%.6lf\n", OptimusPrime(0, 0, 0));
}