#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int n[3];
	char str[7];

	for(int i=0; i<3; i++){
		scanf("%s", str);
		if(strcmp(str, "black")==0) n[i] = 0;
		else if(strcmp(str, "brown")==0) n[i] = 1;
		else if(strcmp(str, "red")==0) n[i] = 2;
		else if(strcmp(str, "orange")==0) n[i] = 3;
		else if(strcmp(str, "yellow")==0) n[i] = 4;
		else if(strcmp(str, "green")==0) n[i] = 5;
		else if(strcmp(str, "blue")==0) n[i] = 6;
		else if(strcmp(str, "violet")==0) n[i] = 7;
		else if(strcmp(str, "grey")==0) n[i] = 8;
		else if(strcmp(str, "white")==0) n[i] = 9;
	}

	if(n[0] > 0) printf("%d", n[0]);
	printf("%d", n[1]);
	if(n[0] > 0 || n[1] > 0){
		for(int i=n[2]; i>0; i--)
			putchar('0');
	}
	puts("");
}