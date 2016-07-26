#include <cstdio>
using namespace std;

int main(){

	unsigned long long sum[1000]={0}, totalSum=0;
	int N, input;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &input);
			sum[i] += input;
		}
		totalSum += sum[i];
	}
	if(N==2){
		printf("1 1");
	}
	else{
		for(int i=0; i<N; i++)
			printf("%d ", (sum[i]-totalSum/(2*(N-1)))/(N-2));
	}

	return 0;
}