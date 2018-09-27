#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N, P[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", P+i);
	if(N == 2){
		printf("%d\n", P[0]*P[1]);
		return 0;
	}

	int lmax[100000], rmax[100000], lmin[100000], rmin[100000];
	int tsum = 0, tmin = 0, tmax = 0;
	for(int i=0; i<N; i++){
		tsum += P[i];
		lmax[i] = tsum - tmin;
		lmin[i] = tsum - tmax;
		if(i > 0){
			lmax[i] = max(lmax[i], lmax[i-1]);
			lmin[i] = min(lmin[i], lmin[i-1]);
		}
		tmin = min(tsum, tmin);
		tmax = max(tsum, tmax);
	}
	tsum = tmin = tmax = 0;
	for(int i=N-1; i>=0; i--){
		tsum += P[i];
		rmax[i] = tsum - tmin;
		rmin[i] = tsum - tmax;
		if(i < N-1){
			rmax[i] = max(rmax[i], rmax[i+1]);
			rmin[i] = min(rmin[i], rmin[i+1]);
		}
		tmin = min(tsum, tmin);
		tmax = max(tsum, tmax);
	}

	long long result = 0;
	for(int i=0; i<N-1; i++)
		result = max(max(1LL*lmax[i]*rmax[i+1], 1LL*lmin[i]*rmin[i+1]), result);
	printf("%lld\n", result);
}