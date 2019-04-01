#include <cstdio>
using namespace std;

int main(){
	while(1){
		char c = getchar();
		if(c == '\n') break;
		putchar(c - ('a'-'A'));
	}
}