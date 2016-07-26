#include <cstdio>
using namespace std;

int main(){
	while(1){
		int A, B;
		scanf("%d %d", &A, &B);
		if(A == 0) break;
		printf("%d\n", A+B);
	}
}