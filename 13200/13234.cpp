#include <cstdio>
using namespace std;

int main(){
	char S[3][5];
	scanf("%s %s %s", S, S[1], S[2]);
	bool val[2] = {S[0][0] == 't', S[2][0] == 't'}, result;
	if(S[1][0] == 'A') result = val[0] && val[1];
	else result = val[0] || val[1];
	puts(result ? "true" : "false");
}