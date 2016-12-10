#include <cstdio>
using namespace std;

int main(){
	for(int t=1; ; t++){
		char A[21], B[21];
		scanf("%s %s", A, B);
		if(A[0] == '#') break;

		int a = 0, b = 0, N;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			char c, d;
			scanf(" %c %c", &c, &d);
			(c==d ? a : b)++;
		}
		printf("%s %d %s %d\n", A, a, B, b);
	}
}