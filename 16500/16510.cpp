#include <cstdio>
using namespace std;

int main(){
	int N, M, pSum[200001] = {0};
	scanf("%d %d", &N, &M);
	for(int i = 0; i < N; ++i){
		int t;
		scanf("%d", &t);
		pSum[i+1] = pSum[i] + t;
	}
	for(int i = 0; i < M; ++i){
		int t;
		scanf("%d", &t);
		if(t >= pSum[N]){
			printf("%d\n", N);
			continue;
		}
		int lo = 0, hi = N;
		while(lo+1 < hi){
			int mid = (lo+hi)/2;
			(t >= pSum[mid] ? lo : hi) = mid;
		}
		printf("%d\n", lo);
	}
}