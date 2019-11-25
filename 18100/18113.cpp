#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, K, M, L[MAX], lo = 1, hi = 1;
	long long sum = 0;
	scanf("%d %d %d", &N, &K, &M);
	for(int i = 0; i < N; ++i){
		scanf("%d", L+i);
		if(L[i] <= K) L[i] = 0;
		else if(L[i] < 2*K) L[i] -= K;
		else L[i] -= 2*K;
		sum += L[i];
		hi = max(L[i]+1, hi);
	}
	if(sum < M){
		puts("-1");
		return 0;
	}

	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long temp = 0;
		for(int i = 0; i < N; ++i)
			temp += L[i]/mid;
		(temp >= M ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}