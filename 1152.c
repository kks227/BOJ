#include <stdio.h>

int main(){
	char c;
	int flag=1;
	int flag2;
	int cnt = 0;
	while(1){
		flag2 = scanf("%c", &c);
		if(flag2 == -1) break;
		if(c == '\n') break;
		if(c == ' ') flag = 1;
		else{
			if(flag == 1) cnt++;
			flag = 0;
		}
	}
	printf("%d\n", cnt);
	return 0;
}