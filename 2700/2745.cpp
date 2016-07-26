#include <cstdio>
using namespace std;

int main(){
	char N[31];
	int B, result = 0;
	scanf("%s %d", N, &B);
	for(int i=0; N[i]; i++)
		result = result*B + N[i] - (N[i]<='9' ? '0' : 'A'-10);
	printf("%d\n", result);
}