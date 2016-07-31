#include <cstdio>
using namespace std;

int A, B, C;

// n^k를 구해주는 함수
int power(int n, int k){
	// 0승은 1이다.
	if(k == 0) return 1;

	// 중간 과정에서 int 범위를 초과할 수 있으므로 long long으로 잠시 전환
	int temp = power(n, k/2);
	int result = 1LL * temp * temp % C;
	if(k%2) result = 1LL * result * n % C;
	return result;
}

int main(){
	scanf("%d %d %d", &A, &B, &C);
	printf("%d\n", power(A, B));
}