#include <cstdio>
using namespace std;
const int MAX = 100000;

int main(){
	int N, K, A[MAX], lo = 0, hi = 1;
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i){
		scanf("%d", A+i);
		hi += A[i];
	}
	while(lo+1 < hi){
		int mid = (lo+hi)/2, cnt = 0, sum = 0;
		for(int i = 0; i < N; ++i){
			sum += A[i];
			if(sum >= mid){
				sum = 0;
				++cnt;
			}
		}
		(cnt >= K ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}