#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, A[300000];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);

	long long result = 0;
	for(int i=0; i<N; i++)
		result += 1LL*A[i]*min(i, K);
	printf("%lld\n", result);
}