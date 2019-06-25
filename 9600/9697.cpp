#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 30;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int N, A[MAX], val[MAX];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%d", A+i);
			val[i] = A[i];
		}
		sort(val, val + N);

		printf("Case #%d:", t);
		for(int i = N-1, j; i >= 0; --i){
			if(A[i] == val[i]) continue;
			for(j = 0; j < i; ++j)
				if(val[i] == A[j]) break;
			if(j > 0){
				printf(" %d", N-j);
				reverse(A, A+j+1);
			}
			printf(" %d", N-i);
			reverse(A, A+i+1);
		}
		puts(" 0");
	}
}