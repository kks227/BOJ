#include <cstdio>
using namespace std;

int main(){

	char c;
	int level, temp, n = 0, cnt = 0;
	
	while(!feof(stdin)){
		c = getchar();
		if(c < '0') break;
		cnt++;
		n += c-'0';
	}
	if(cnt == 1) level = 0;
	else{
		level = 1;
		while(n >= 10){
			temp = n;
			n = 0;
			while(temp){
				n += temp%10;
				temp /= 10;
			}
			level++;
		}
	}
	printf("%d\n%s\n", level, n%3?"NO":"YES");

	return 0;
}