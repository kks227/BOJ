#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	if(N <= 2) printf("%d\n", N-1);
	else{
		for(int i=2; i*i<=N; i++){
			if(N%i == 0){
				printf("%d\n", N-N/i);
				return 0;
			}
		}
		printf("%d\n", N-1);
	}
}