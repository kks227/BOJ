#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, x[5000], y[5000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", x+i, y+i);

	double lo = 0, hi = 1000000;
	while(hi-lo > 1e-4){
		double mid = (lo+hi)/2;
		bool possible = true;

		double L = x[0], R = x[N-1];
		for(int i=0; i<N-1; i++){
			if(y[i] == y[i+1] && y[i] > mid){
				possible = false;
				break;
			}
			double X = x[i] + (x[i+1]-x[i]) * (mid-y[i]) / (y[i+1]-y[i]);
			if(y[i] > y[i+1]) L = max(L, X);
			else if(y[i] < y[i+1]) R = min(R, X);
			if(L > R){
				possible = false;
				break;
			}
		}
		(possible ? hi : lo) = mid;
	}
	printf("%.2lf\n", hi);
}