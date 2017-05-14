#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, T, lo = 0, hi = 0, L[1000], R[1000];
	long long lsum = 0, rsum = 0;
	scanf("%d %d", &N, &T);
	for(int i=0; i<N; i++){
		scanf("%d %d", L+i, R+i);
		lsum += L[i];
		rsum += R[i];
		lo = max(lo, L[i]);
		hi = max(hi, R[i]);
	}
	if(lsum > T || rsum < T){
		puts("-1");
		return 0;
	}

	lo--;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		long long temp = 0;
		for(int i=0; i<N; i++)
			temp += min(R[i], mid);
		(temp >= T ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}