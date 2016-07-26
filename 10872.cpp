#include <cstdio>
using namespace std;

int main(){
	int N, result = 1;
	scanf("%d", &N);
	for(int i=2; i<=N; i++)
		result *= i;
	printf("%d\n", result);
}