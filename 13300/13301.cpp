#include <cstdio>
using namespace std;

int main(){
	long long fibo[81] = {1, 1};
	for(int i=2; i<=80; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	int N;
	scanf("%d", &N);
	printf("%lld\n", (fibo[N-1]+fibo[N])*2);
}