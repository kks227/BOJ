#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

int len, pos;
char str[31];

int getValue(){
	int result = 0;
	if(str[pos++] == '('){
		while(1){
			if(pos >= len || str[pos] == ']'){
				puts("0");
				exit(0);
			}
			if(str[pos] == ')') break;
			result += getValue();
			pos++;
		}
		if(result == 0) result++;
		return result * 2;
	}
	else{
		while(1){
			if(pos >= len || str[pos] == ')'){
				puts("0");
				exit(0);
			}
			if(str[pos] == ']') break;
			result += getValue();
			pos++;
		}
		if(result == 0) result++;
		return result * 3;
	}
}

int main(){

	scanf("%s", str);
	len = strlen(str);
	int result = 0;
	while(pos < len){
		if(str[pos] == ')' || str[pos] == ']'){
			puts("0");
			return 0;
		}
		result += getValue();
		pos++;
	}
	printf("%d\n", result);

	return 0;
}