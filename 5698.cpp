#include <cstdio>
using namespace std;

int main(){
	char s[1050];
	while(1){
		gets(s);
		if(s[0]=='*') break;
		char c = s[0]&31, result = 'Y';
		for(int i=1; s[i]; i++)
			if(s[i]==' ' && (s[i+1]&31)!=c){
				result = 'N';
				break;
			}
		printf("%c\n", result);
	}
}