#include <cstdio>
using namespace std;
const int MAX = 300000;

int main(){
	int N, A[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	int result = N;
	for(int i = N-1; i >= 0; --i)
		if(result == A[i]) --result;
	printf("%d\n", result);
}