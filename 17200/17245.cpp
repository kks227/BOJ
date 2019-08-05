#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, A[MAX];
	long long K = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%d", A+i*N+j);
			K += A[i*N+j];
		}
	}
	K = K/2 + K%2;
	N *= N;
	sort(A, A+N);
	long long pSum[MAX+1] = {0,};
	for(int i = 0; i < N; ++i)
		pSum[i+1] = pSum[i] + A[i];

	int lo = -1, hi = A[N-1];
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		int p = lower_bound(A, A+N, mid) - A;
		(pSum[p] + 1LL*(N-p)*mid >= K ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}