#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N;
	long long A[1000000] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		long long B;
		scanf("%lld", &B);
		while(B){
			A[i] = A[i]*10 + B%10;
			B /= 10;
		}
	}
	sort(A, A+N);
	for(int i=0; i<N; i++)
		printf("%lld\n", A[i]);
}