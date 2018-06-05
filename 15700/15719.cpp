#include <cstdio>
using namespace std;

int main(){
	int N;
	long long sum = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		sum += A;
	}
	printf("%lld\n", sum - 1LL*N*(N-1)/2);
}