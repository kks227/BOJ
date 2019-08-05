#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, result;
	scanf("%d %d", &N, &result);
	for(int i = 1; i < N; ++i){
		int A;
		scanf("%d", &A);
		result = max(A, result);
	}
	printf("%d\n", result);
}