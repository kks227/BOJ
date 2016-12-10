#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++){
		int N, result = 0;
		char A[101], B[101];
		scanf("%d %s %s", &N, A, B);
		for(int i=0; i<N; i++)
			result += A[i]!=B[i];
		printf("Case %d: %d\n", t, result);
	}
}