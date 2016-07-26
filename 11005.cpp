#include <cstdio>
using namespace std;

inline char i2c(int n){ return n<10 ? n+'0' : n-10+'A'; }

int main(){
	int N, B, pos = 0;
	scanf("%d %d", &N, &B);
	char r[32] = {0};
	while(N){
		r[pos++] = i2c(N%B);
		N /= B;
	}
	for(pos--; pos>=0; pos--)
		putchar(r[pos]);
}