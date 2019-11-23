#include <cstdio>
using namespace std;

int main(){
	int A, B, result = 0;
	scanf("%d %d", &A, &B);
	while(A > B){
		if(A%2) ++result;
		A = (A+1)/2;
		++result;
	}
	printf("%d\n", result + B-A);
}