#include <cstdio>
using namespace std;

int main(){
	int N, result = 1;
	scanf("%d", &N);
	for(; N>1; result++){
		if(N%2) N = 3*N+1;
		else N /= 2;
	}
	printf("%d\n", result);
}