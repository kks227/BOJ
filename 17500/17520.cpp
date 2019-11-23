#include <cstdio>
using namespace std;
const int MOD = 16769023;

int main(){
	int N;
	scanf("%d", &N);
	int result = 1;
	for(int i = 0; i < (N+1)/2; ++i)
		result = result * 2 % MOD;
	printf("%d\n", result);
}