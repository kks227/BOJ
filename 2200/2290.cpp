#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int s, len;
	char n[11];
	scanf("%d %s", &s, n);
	len = strlen(n);
	bool LCD[10][7] = {
		1, 1, 1, 0, 1, 1, 1,
		0, 0, 1, 0, 0, 1, 0,
		1, 0, 1, 1, 1, 0, 1,
		1, 0, 1, 1, 0, 1, 1,
		0, 1, 1, 1, 0, 1, 0,
		1, 1, 0, 1, 0, 1, 1,
		1, 1, 0, 1, 1, 1, 1,
		1, 0, 1, 0, 0, 1, 0,
		1, 1, 1, 1, 1, 1, 1,
		1, 1, 1, 1, 0, 1, 1
	};

	int i = 0;
	while(1){
		putchar(' ');
		for(int j=0; j<len; j++){
			for(int k=0; k<s; k++)
				putchar(LCD[n[j]-'0'][i*3]?'-':' ');
			printf("   ");
		}
		putchar('\n');
		if(i == 2) break;
		for(int k=0; k<s; k++){
			for(int j=0; j<len; j++){
				putchar(LCD[n[j]-'0'][i*3+1]?'|':' ');
				for(int l=0; l<s; l++)
					putchar(' ');
				putchar(LCD[n[j]-'0'][i*3+2]?'|':' ');
				putchar(' ');
			}
			putchar('\n');
		}
		i++;
	}

	return 0;
}