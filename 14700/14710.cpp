#include <cstdio>
using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	bool result = false;
	for(int i=0; i<12; i++)
		if(a*12 % 360 == b) result = true;
	putchar(result ? 'O' : 'X');
}