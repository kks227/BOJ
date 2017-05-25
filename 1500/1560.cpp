#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char N[72] = {'0',};
	scanf("%s", N+1);
	if(strcmp(N+1, "1") == 0){
		puts("1");
		return 0;
	}
	int start = strlen(N+1), carry = 1;
	for(int i=start; i>=0; i--){
		int val = N[i]-'0' - carry;
		carry = (val < 0);
		N[i] = (val+10)%10+'0';
	}
	for(int i=start; i>=0; i--){
		int val = (N[i]-'0')*2 + carry;
		carry = (val >= 10);
		N[i] = val%10+'0';
	}
	for(int i=0, j=1; i<=start; i++){
		if(j && N[i]=='0') continue;
		j = 0;
		putchar(N[i]);
	}
}