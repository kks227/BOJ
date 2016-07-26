#include <cstdio>
#include <cstring>
using namespace std;

int main(){

	int fact[5] = {1, 2, 6, 24, 120}, len, result;
	char N[6];
	while(1){
		scanf("%s", N);
		if(N[0] == '0') break;
		len = strlen(N);
		result = 0;
		for(int i=len-1; i>=0; i--)
			result += fact[len-1-i]*(N[i]-'0');
		printf("%d\n", result);
	}

	return 0;
}