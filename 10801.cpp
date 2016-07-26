#include <cstdio>
using namespace std;

int main(){
	int c[10], A=0, B=0, n;
	for(int i=0; i<10; i++)
		scanf("%d", c+i);
	for(int i=0; i<10; i++){
		scanf("%d", &n);
		if(c[i]<n) B++;
		else if(c[i]>n) A++;
	}
	putchar( A==B ? 'D' : (A>B?'A':'B') );
}