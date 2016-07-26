#include <cstdio>
using namespace std;

int main(){

	int N;
	scanf("%d", &N);

	int temp = N;
	int p, q;
	int result = 0;
	do{
		p = temp%10;
		q = temp/10 + p;
		q %= 10;
		temp = p*10 + q;
		result++;
	}while(temp != N);
	
	printf("%d\n", result);

	return 0;
}