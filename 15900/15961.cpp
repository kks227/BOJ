#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, D, K, C, A[3000000], cnt[3000] = {0}, temp = 0;
	scanf("%d %d %d %d", &N, &D, &K, &C);
	C--;
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		A[i]--;
		if(i >= N-K){
			if(cnt[A[i]]++ == 0) temp++;
		}
	}

	int result = 0;
	for(int i=0; i<N; i++){
		result = max(temp + !cnt[C], result);
		if(cnt[A[i]]++ == 0) temp++;
		if(--cnt[A[(i+N-K)%N]] == 0) temp--;
	}
	printf("%d\n", result);
}