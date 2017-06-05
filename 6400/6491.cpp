#include <cstdio>
using namespace std;

int main(){
	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;

		int sum = 0;
		for(int i=1; i<=N/2; i++)
			if(N%i == 0) sum += i;
		printf("%d ", N);
		if(sum == N) puts("PERFECT");
		else puts(sum < N ? "DEFICIENT" : "ABUNDANT");
	}
}