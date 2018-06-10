#include <cstdio>
using namespace std;

int main(){
	int N, M;
	long long A;
	scanf("%d %d %lld", &N, &M, &A);
	A %= M;
	for(int i=1; i<N; i++){
		long long B;
		scanf("%lld", &B);
		A = A*B % M;
	}
	printf("%lld\n", A);
}