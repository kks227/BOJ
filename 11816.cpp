#include <cstdio>
using namespace std;

int main(){
	char X[20] = "";
	scanf("%s", X);
	int result = 0;
	if(X[0] == '0'){
		if(X[1] == 'x'){
			for(int i=2; X[i]; i++)
				result = result*16 + (X[i]>='a' ? X[i]-'a'+10 : X[i]-'0'); 
		}
		else{
			for(int i=1; X[i]; i++)
				result = result*8 + X[i]-'0';
		}
	}
	else{
		for(int i=0; X[i]; i++)
			result = result*10 + X[i]-'0';
	}
	printf("%d\n", result);
}