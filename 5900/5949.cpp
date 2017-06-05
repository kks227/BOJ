#include <cstdio>
using namespace std;

int main(){
	int N, val[4], L = 0;
	scanf("%d", &N);
	while(N){
		val[L++] = N%1000;
		N /= 1000;
	}
	for(int i=--L; i>=0; i--){
		printf(i==L?"%d":"%03d", val[i]);
		if(i > 0) putchar(',');
	}
}