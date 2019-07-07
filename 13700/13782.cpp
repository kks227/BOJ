#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000;
const int MAX_F = 30;

int B, F, c[MAX_F], to[MAX_F+1][MAX+1];
double r[MAX_F], dp[MAX_F+1][MAX+1];

double filter(int pos, int b){
	double &ret = dp[pos][b];
	if(ret >= 0) return ret;
	if(pos == F) return ret = 1;

	ret = 0;
	double p = 1-r[pos];
	for(int i = 1; c[pos]*i <= b; ++i){
		double temp = filter(pos+1, b-c[pos]*i)*(1-p);
		if(temp > ret){
			ret = temp;
			to[pos][b] = i;
		}
		p *= (1-r[pos]);
	}
	return ret;
}

int trace(int pos, int b){
	if(pos == F) return 0;
	return c[pos]*to[pos][b] + trace(pos+1, b-c[pos]*to[pos][b]);
}



int main(){
	while(1){
		scanf("%d %d", &B, &F);
		if(B == 0) break;

		for(int i = 0; i < F; ++i){
			scanf("%d %lf", c+i, r+i);
			fill(dp[i], dp[i]+MAX+1, -1);
		}
		fill(dp[F], dp[F]+MAX+1, -1);
		double result = filter(0, B);
		printf("%d %.3lf\n", trace(0, B), result);
	}
}