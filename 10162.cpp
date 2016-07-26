#include <cstdio>
using namespace std;

int main(){

	int T, A, B, C;
	scanf("%d", &T);
	if(T%10) puts("-1");
	else{
		C = T % 60 / 10;
		A = (T - T % 60) / 60;
		B = A % 5;
		A /= 5;
		printf("%d %d %d\n", A, B, C);
	}

	return 0;
}