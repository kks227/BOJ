#include <cstdio>
using namespace std;

int main(){
	int c;
	for(int i=0; (c=getchar()) > '\n'; i++)
		printf("%d\n", i);
}