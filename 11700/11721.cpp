#include <cstdio>
using namespace std;

int main(){
	int c, cnt = 0;
	while((c=getchar()) != -1){
		putchar(c);
		if(++cnt == 10){
			cnt = 0;
			putchar('\n');
		}
	}
}