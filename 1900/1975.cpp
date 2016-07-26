#include <cstdio>
using namespace std;

int main(){

	int T, N, result, temp;
	scanf("%d", &T);
	for(int i=0; i<T; i++){
		scanf("%d", &N);
		if(N == 1){
			printf("0\n");
			continue;
		}
		result = 1;
		for(int j=2; j<N; j++){
			temp = N;
			while(temp%j == 0){
				result++;
				temp /= j;
			}
		}
		printf("%d\n", result);
	}

	return 0;
}