#include <cstdio>
using namespace std;

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	for(int i=0; i<=K; i++, N*=10) result += N;
	printf("%d\n", result);
}