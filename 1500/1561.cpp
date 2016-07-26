#include <cstdio>
using namespace std;

int N, M, T[10000];

long long cntChildren(long long minute){
	long long result = M;
	for(int i=0; i<M; i++)
		result += minute/T[i];
	return result;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++)
		scanf("%d", T+i);
	if(N <= M){
		printf("%d\n", N);
		return 0;
	}

	long long lo = 0, hi = 30LL*N+1;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		if(cntChildren(mid) >= N) hi = mid;
		else lo = mid;
	}
	int remain = cntChildren(hi)-N, result = M-1;
	for(int i=M-1; i>=0; i--){
		if(hi%T[i] != 0) result--;
		else if(remain == 0) break;
		else{
			remain--;
			result--;
		}
	}
	printf("%d\n", result+1);
}