#include <cstdio>
using namespace std;

int main(){
	int N, A[8] = {1, 2, 3, 4, 5, 4, 3, 2};
	scanf("%d", &N);
	printf("%d\n", A[(N-1)%8]);
}