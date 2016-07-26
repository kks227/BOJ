#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int A, B;
		scanf("%d,%d", &A, &B);
		printf("%d\n", A+B);
	}
}