#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, A;
	scanf("%d %d", &N, &A);
	int result = A;
	int sum = max(A, 0);
	for(int i = 1; i < N; ++i){
		scanf("%d", &A);
		sum = max(sum, 0) + A;
		result = max(sum, result);
	}
	printf("%d\n", result);
}