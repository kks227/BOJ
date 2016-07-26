#include <cstdio>
using namespace std;

int main(){
	int A, B, C[7], i;
	scanf("%d %d", &A, &B);
	for(i=0; i<7; i++){
		C[i] = A%10 + B%10;
		A /= 10;
		B /= 10;
	}
	for(i=6; C[i]==0; i--);
	for(; i>=0; i--)
		printf("%d", C[i]);
}