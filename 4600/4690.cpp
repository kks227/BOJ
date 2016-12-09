#include <cstdio>
#define T(n) (n*n*n)
using namespace std;

int main(){
	for(int a=1; a<=100; a++)
		for(int b=2; b<a; b++)
			for(int c=b+1; T(a)>T(b)+T(c); c++)
				for(int d=c+1; T(a)>=T(b)+T(c)+T(d); d++)
					if(T(a) == T(b)+T(c)+T(d))
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
}