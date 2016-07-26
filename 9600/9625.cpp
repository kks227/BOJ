#include <cstdio>
using namespace std;

int main(){

	int K, fibo[46] = {0, 1};
	scanf("%d", &K);
	for(int i=2; i<=K; i++)
		fibo[i] = fibo[i-2] + fibo[i-1];
	printf("%d %d\n", fibo[K-1], fibo[K]);

	return 0;
}