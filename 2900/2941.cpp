#include <cstdio>
using namespace std;

int main(){
	char S[101];
	scanf("%s", S);
	int result = 0;
	for(int i=0; S[i]; i++){
		switch(S[i]){
			case 'c':
			if(S[i+1] == '=' || S[i+1] == '-') i++;
			break;
			case 'd':
			if(S[i+1] == '-') i++;
			else if(S[i+1] == 'z' && S[i+2] == '=') i+=2;
			break;
			case 'l':
			case 'n':
			if(S[i+1] == 'j') i++;
			break;
			case 's':
			case 'z':
			if(S[i+1] == '=') i++;
		}
		result++;
	}
	printf("%d\n", result);
}