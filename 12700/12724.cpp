#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 800;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N, A[MAX], B[MAX];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", A+i);
		for(int i = 0; i < N; ++i)
			scanf("%d", B+i);
		sort(A, A+N);
		sort(B, B+N);
		long long result = 0;
		for(int i = 0; i < N; ++i)
			result += 1LL*A[i]*B[N-i-1];
		printf("Case #%d: %lld\n", t, result);
	}
}