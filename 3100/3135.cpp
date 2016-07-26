#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	int A, B, N;
	scanf("%d %d %d", &A, &B, &N);
	int result = abs(A-B);
	for(int i=0; i<N; i++){
		int M;
		scanf("%d", &M);
		result = min(result, abs(M-B)+1);
	}
	printf("%d\n", result);
}