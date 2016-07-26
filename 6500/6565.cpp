#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

void parse(char *s, int &cur, int &p){
	p = 0;
	while(cur >= 0 && isdigit(s[cur])){
		p *= 10;
		p += s[cur]-'0';
		cur--;
	}
}

int main(){
	char S[24];
	int a, b, c, i;
	while(1){
		scanf("%s", S);
		i = strlen(S) - 1;
		parse(S, i, c);
		parse(S, --i, b);
		parse(S, --i, a);
		printf("%s\n", a+b==c?"True":"False");
		if(strcmp(S, "0+0=0") == 0) break;
	}

	return 0;
}