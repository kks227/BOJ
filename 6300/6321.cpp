#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++){
		printf("String #%d\n", t);
		char c;
		while((c=getchar()) != '\n') putchar((c-'A'+1)%26+'A');
		puts("");
		puts("");
	}
}