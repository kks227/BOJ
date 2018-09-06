#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[100000];
	long long result = 0, sum = 0;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", A+i);
		sum += A[i];
		if(i >= M-1){
			result = max(sum, result);
			sum -= A[i-M+1];
		}
	}
	printf("%lld\n", result);
}