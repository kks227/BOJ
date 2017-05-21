#include <cstdio>
using namespace std;

int main(){
	int N, M, A;
	scanf("%d %d %d", &N, &M, &A);
	A--;
	while(1){
		int X;
		scanf("%d", &X);
		if(X == M/2+1){
			puts("0");
			break;
		}
		A = (N + A + X-M/2-1) % N;
		printf("%d\n", A+1);
	}
}