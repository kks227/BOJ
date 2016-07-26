#include <cstdio>
using namespace std;

#define START 524288

int main(){

	int N, X, div, binary[20] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &X);
		div = START;
		for(int j=19; j>=0; j--){
			if(X >= div){
				binary[j]++;
				X -= div;
			}
			if(X == 0) break;
			div /= 2;
		}
	}

	unsigned long long result = 0;
	int mtp = 1;
	for(int i=0; i<20; i++){
		result += (unsigned long long)(N - binary[i]) * binary[i] * mtp;
		mtp *= 2;
	}
	printf("%llu\n", result);

	return 0;
}