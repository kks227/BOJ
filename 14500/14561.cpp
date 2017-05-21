#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		long long A;
		int N, L = 0;
		scanf("%lld %d", &A, &N);
		char X[40] = {0}, Y[40] = {0};
		while(A){
			X[L++] = (A % N) + '0';
			A /= N;
		}
		strcpy(Y, X);
		reverse(Y, Y+L);
		printf("%d\n", !strcmp(X, Y));
	}
}