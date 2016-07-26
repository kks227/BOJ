#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, A[20000], B, result = 0;
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++)
			scanf("%d", A+i);
		sort(A, A+N);
		for(int i=0; i<M; i++){
			scanf("%d", &B);
			result += A+N - upper_bound(A, A+N, B);
		}
		printf("%d\n", result);
	}
}