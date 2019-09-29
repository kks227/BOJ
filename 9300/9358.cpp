#include <cstdio>
using namespace std;
const int MAX = 100;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N;
		long long A[MAX];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%lld", A+i);
		while(N > 2){
			for(int i = 0; i < N/2; ++i)
				A[i] += A[N-i-1];
			if(N%2){
				A[N/2] *= 2;
				N = N/2 + 1;
			}
			else N /= 2;
		}
		printf("Case #%d: %s\n", t, (A[0] > A[1] ? "Alice" : "Bob"));
	}
}