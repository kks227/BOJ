#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);

	long long result = 0;
	int p = upper_bound(A, A+N, 0) - A;
	for(int i=N-2; i>=p; i-=2)
		result += max(1LL*A[i]*A[i+1], 0LL+A[i]+A[i+1]); // for 1,k
	if((N-p)%2) result += A[p];
	for(int i=0; i+1<p; i+=2)
		result += 1LL*A[i]*A[i+1];
	if(p>0 && p%2) result += A[p-1];
	printf("%lld\n", result);
}