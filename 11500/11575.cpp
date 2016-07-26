#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int a, b;
		char s[1000000];
		scanf("%d %d %s", &a, &b, s);
		for(int i=0; s[i]; i++)
			putchar(((s[i]-'A')*a+b)%26+'A');
		puts("");
	}
}