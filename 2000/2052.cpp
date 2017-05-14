#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	unsigned char B[8] = {0};
	char S[10] = {0};
	int N, K;
	scanf("%d", &N);
	K = 1023 - N;
	for(int i=4; i<8; i++){
		if(K%2) B[6] |= (1<<i);
		K /= 2;
	}
	for(int i=0; i<7; i++){
		if(K%2) B[7] |= (1<<i);
		K /= 2;
	}
	double f;
	memcpy(&f, B, 8);
	sprintf(S, "%%.%dlf\n", N);
	printf(S, f);
}