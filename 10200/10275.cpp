#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, result = 0;
		long long A, B, K;
		scanf("%d %lld %lld", &N, &A, &B);
		if(A > B) swap(A, B);
		K = 1LL << N;
		for(; A%K; K/=2, result++);
		printf("%d\n", result);
	}
}