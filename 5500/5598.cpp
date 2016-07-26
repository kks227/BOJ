#include <cstdio>
using namespace std;

int main(){
	int c;
	while((c=getchar()) != '\n')
		putchar((c-'A'+23)%26+'A');
}