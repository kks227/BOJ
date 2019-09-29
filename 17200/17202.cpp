#include <cstdio>
using namespace std;

int main(){
	int d[16];
	for(int i = 0; i < 16; i += 2)
		scanf("%1d", d+i);
	for(int i = 1; i < 16; i += 2)
		scanf("%1d", d+i);
	for(int k = 0; k < 14; ++k)
		for(int i = 0; i < 15-k; ++i)
			d[i] = (d[i] + d[i+1]) % 10;
	printf("%1d%1d\n", d[0], d[1]);
}