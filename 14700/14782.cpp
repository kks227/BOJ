#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i)
		if(N%i == 0) result += i;
	printf("%d\n", result);
}