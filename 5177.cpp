#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;

void trim(char *s, char *dest){
	int i=0, j=0;
	bool blank = true, barrier = true;
	while(s[i] != '\0'){
		switch(s[i]){
		case ' ':
			blank = true;
			break;
		case ',':
		case ';':
			dest[j++] = ',';
			blank = false;
			barrier = true;
			break;
		case '.':
			dest[j++] = '.';
			blank = false;
			barrier = true;
			break;
		case ':':
			dest[j++] = ':';
			blank = false;
			barrier = true;
			break;
		case '(':
		case '[':
		case '{':
			dest[j++] = '(';
			blank = false;
			barrier = true;
			break;
		case ')':
		case ']':
		case '}':
			dest[j++] = ')';
			blank = false;
			barrier = true;
			break;
		default:
			if(blank && !barrier) dest[j++] = ' ';
			if(islower(s[i])) dest[j++] = s[i]-32;
			else dest[j++] = s[i];
			blank = false;
			barrier = false;
		}
		i++;
	}
	dest[j] = '\0';
}

int main(){

	int T;
	scanf("%d\n", &T);
	char s[1001], s1[1001], s2[1001];
	for(int t=1; t<=T; t++){
		gets(s);
		trim(s, s1);
		gets(s);
		trim(s, s2);
		printf("Data Set %d: %sequal\n\n", t, strcmp(s1, s2)==0?"":"not ");
	}

	return 0;
}