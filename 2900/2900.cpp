#include <cstdio>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, K, Q, A[MAX] = {0,}, val[MAX+1] = {0,};
	scanf("%d %d", &N, &K);
	for(int i = 0; i < K; ++i){
		int k;
		scanf("%d", &k);
		++val[k];
	}
	for(int i = 1; i <= MAX; ++i){
		if(val[i] == 0) continue;
		for(int j = 0; j < N; j += i)
			A[j] += val[i];
	}

	long long pSum[MAX+1] = {0,};
	for(int i = 0; i < N; ++i)
		pSum[i+1] = pSum[i] + A[i];
	scanf("%d", &Q);
	for(int i = 0; i < Q; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		printf("%lld\n", pSum[e+1] - pSum[s]);
	}
}