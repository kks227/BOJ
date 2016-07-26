#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int H, C, x[200];
double dp[200][200];

inline double interpolate(int i, int j, int k){
	return x[i] + 1.0*(x[j]-x[i])*(k-i)/(j-i);
}

double minError(int pos, int used){
	double &ret = dp[pos][used];
	if(ret >= 0) return ret;

	if(used == C-1){
		ret = 0;
		for(int i=pos+1; i<H-1; i++)
			ret += abs(interpolate(pos, H-1, i) - x[i]);
	}
	else{
		ret = 200000000.0;
		for(int i=pos+1; i<=H-C+used; i++){
			double error = 0;
			for(int j=pos+1; j<i; j++)
				error += abs(interpolate(pos, i, j) - x[j]);
			ret = min(ret, minError(i, used+1) + error);
		}
	}
	return ret;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &H, &C);
		for(int i=0; i<H; i++)
			scanf("%d", x+i);
		for(int i=0; i<200; i++)
			for(int j=0; j<200; j++)
				dp[i][j] = -1;
		printf("%.4lf\n", minError(0, 1)/H);
	}
}