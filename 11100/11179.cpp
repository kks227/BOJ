#include <cstdio>
using namespace std;

int main(){
	unsigned int N, M = 0;
	scanf("%u", &N);
	int bits;
	for(bits=31; bits>=0 && !(N & 1 << bits); bits--);
	for(int i=bits; i>=0; i--)
		if(N & 1 << i) M |= 1 << (bits-i);
	printf("%u\n", M);
}