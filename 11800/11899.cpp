#include <cstdio>
using namespace std;

int main(){
	char S[51];
	scanf("%s", S);
	int result = 0, s = 0;
	for(int i=0; S[i]; i++){
		if(S[i] == ')'){
			if(s == 0) result++;
			else s--;
		}
		else s++;
	}
	printf("%d\n", result += s);
}