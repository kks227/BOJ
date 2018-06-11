#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[100000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		A[i]--;
	}
	int lo = 1, hi = N+1;
	while(lo+1 < hi){
		int mid = (lo+hi)/2, temp = 0, cnt[500000] = {0,}, vcnt = 0;
		for(int i=0, j=0; i<N; i++){
			if(cnt[A[i]]++ > 0) vcnt++;
			if(j == mid){
				if(--cnt[A[i-mid]] > 0) vcnt--;
			}
			else j++;

			if(j == mid && vcnt == 0){
				if(++temp == M) break;
				while(j > 0) cnt[A[i-(--j)]]--;
			}
		}
		(temp >= M ? lo : hi) = mid;
	}
	printf("%d\n", lo);
}