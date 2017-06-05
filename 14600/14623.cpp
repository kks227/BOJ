#include <cstdio>
using namespace std;

int main(){
	int B[2] = {0};
	for(int i=0; i<2; i++){
		while(1){
			char c = getchar();
			if(c == '\n') break;
			B[i] = B[i]*2 + c-'0';
		}
	}
	long long A = 1LL*B[0]*B[1];
	int L = 0, b[64];
	while(A){
		b[L++] = A%2;
		A /= 2;
	}
	while(L) putchar('0'+b[--L]);
}