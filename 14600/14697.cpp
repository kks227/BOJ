#include <cstdio>
using namespace std;

int main(){
	int A, B, C, N;
	scanf("%d %d %d %d", &A, &B, &C, &N);
	for(int i=0; i<=300; i++){
		for(int j=0; j<=300; j++){
			for(int k=0; k<=300; k++){
				if(A*i+B*j+C*k == N){
					puts("1");
					return 0;
				}
			}
		}
	}
	puts("0");
}