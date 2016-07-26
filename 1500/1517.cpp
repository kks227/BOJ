#include <cstdio>
#include <algorithm>
using namespace std;

int N, A[500000], B[500000];

long long cntSwap(int lo, int hi){
	if(lo+1 == hi) return 0;

	int mid = (lo+hi)/2;
	long long result = cntSwap(lo, mid) + cntSwap(mid, hi);
	for(int i=lo, j=mid, k=0; i<mid || j<hi; k++){
		if(i<mid && (j==hi || A[i]<=A[j])) B[k] = A[i++];
		else{
			B[k] = A[j++];
			result += mid-i;
		}
	}
	copy(B, B+(hi-lo), A+lo);
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	printf("%lld\n", cntSwap(0, N));
}