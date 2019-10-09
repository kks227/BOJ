#include <cstdio>
using namespace std;
const int MAX_N = 1000;
const int MAX = 2000001;

inline int get(int cnt[MAX], int k){ return (k >= 0 ? cnt[k] : 0); }

int main(){
	int K, M, N, cnt[MAX] = {0,}, pSum[MAX_N+1] = {0,}, S;
	long long result = 0;
	scanf("%d %d %d", &K, &M, &N);
	for(int j = 0; j < M; ++j){
		scanf("%d", pSum+j+1);
		pSum[j+1] += pSum[j];
	}
	S = pSum[M];
	for(int j = 0; j < M; ++j){
		++cnt[ pSum[j] ];
		++cnt[ S-pSum[j] ];
	}
	for(int j = 1; j < M; ++j){
		for(int k = j+1; k < M; ++k){
			++cnt[ pSum[k]-pSum[j] ];
			++cnt[ S-pSum[k]+pSum[j] ];
		}
	}
	pSum[0] = 0;
	for(int j = 0; j < N; ++j){
		scanf("%d", pSum+j+1);
		pSum[j+1] += pSum[j];
	}
	S = pSum[N];
	for(int j = 0; j < N; ++j){
		result += get(cnt, K-pSum[j]);
		result += get(cnt, K-S+pSum[j]);
	}
	for(int j = 1; j < N; ++j){
		for(int k = j+1; k < N; ++k){
			result += get(cnt, K-pSum[k]+pSum[j]);
			result += get(cnt, K-S+pSum[k]-pSum[j]);
		}
	}
	printf("%lld\n", result);
}