#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 8;

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
		int result = 0;
		for(int i = 0; i < N; ++i)
			result += A[i]*B[N-i-1];
		printf("Case #%d: %d\n", t, result);
	}
}