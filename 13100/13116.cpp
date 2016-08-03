#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int A, B, p = 512;
		scanf("%d %d", &A, &B);
		while(A != B){
			if(p <= A) A /= 2;
			if(p <= B) B /= 2;
			p /= 2;
		}
		printf("%d0\n", A);
	}
}