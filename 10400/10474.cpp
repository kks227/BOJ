#include <cstdio>
using namespace std;

int main(){
	while(1){
		int A, B;
		scanf("%d %d", &A, &B);
		if(A==0) break;
		printf("%d %d / %d\n", A/B, A%B, B);
	}
}