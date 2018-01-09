#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int K, c[11], a, b, N;
	scanf("%d", &K);
	for(int i=K; i>=0; i--)
		scanf("%d", c+i);
	scanf("%d %d %d", &a, &b, &N);
	double ans = 0, d = 1.0*(b-a)/N;
	for(int i=0; i<=K; i++)
		ans += c[i]*(pow(b, i+1)-pow(a, i+1))/(i+1);

	double lo = 0, hi = d, mid;
	while(1){
		mid = (lo+hi)/2;
		double temp = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<=K; j++)
				temp += c[j]*pow(a+i*d+mid, j);
		temp *= d;
		if(abs(temp-ans) < 1e-4) break;

		(temp > ans ? hi : lo) = mid;
	}
	printf("%.6lf\n", mid);
}