#include <cstdio>
using namespace std;
const int MOD = 14579;

int main(){
	int A, B, result = 0, temp = 0;
	scanf("%d %d", &A, &B);
	for(int i=1; i<=A; i++)
		temp = (temp + i) % MOD;
	result = temp;
	for(int i=A+1; i<=B; i++){
		temp = (temp + i) % MOD;
		result = (result * temp) % MOD;
	}
	printf("%d\n", result);
}