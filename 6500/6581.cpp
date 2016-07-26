#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int line = 0, len;
	char word[81];
	while(scanf("%s", word) > 0){
		len = strlen(word);
		if(strcmp(word, "<br>") == 0){
			puts("");
			line = 0;
		}
		else if(strcmp(word, "<hr>") == 0){
			if(line) puts("");
			puts("--------------------------------------------------------------------------------");
			line = 0;
		}
		else if(line + len > 80){
			printf("\n%s", word);
			line = len + 1;
		}
		else{
			if(line) putchar(' ');
			printf("%s", word);
			line += len + 1;
		}
	}

	return 0;
}