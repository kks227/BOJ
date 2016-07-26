#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int N;
	scanf("%d\n", &N);
	for(int i=0; i<N; i++){
		char c;
		do{
			c = getchar();
			if(isupper(c)) c += 'a'-'A';
			putchar(c);
		}while(c != '\n');
	}
}