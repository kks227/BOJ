#include <cstdio>
using namespace std;

int main(){
	int N, M, sum = 0, cnt[1000] = {1,};
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		sum = (sum + A) % M;
		cnt[sum]++;
	}
	long long result = 0;
	for(int i=0; i<M; i++)
		result += 1LL * cnt[i] * (cnt[i]-1) / 2;
	printf("%lld\n", result);
}