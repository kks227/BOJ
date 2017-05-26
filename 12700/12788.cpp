#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, K, A[1000], sum = 0;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	sort(A, A+N);
	for(int i=1; i<=N; i++){
		sum += A[N-i];
		if(sum >= M*K){
			printf("%d\n", i);
			return 0;
		}
	}
	puts("STRESS");
}