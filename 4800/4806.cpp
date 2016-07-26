#include <cstdio>
using namespace std;

int main(){
	int c, cnt = 0;
	while((c=getchar()) != -1)
		if(c == '\n') cnt++;
	printf("%d\n", cnt);
}