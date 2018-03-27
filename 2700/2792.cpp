#include <cstdio>
using namespace std;

int main(){
	int N, M, A[300000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++)
		scanf("%d", A+i);
	int lo = 0, hi = 1e9;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long sum = 0;
		for(int i=0; i<M; i++)
			sum += (A[i]-1) / mid + 1;
		(sum <= N ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}