#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

int main(){
	int s = 0, e = 0, result = 0, rs, re;
	char S[10001] = {0};
	for(int i=0; ; i++){
		S[i] = getchar();
		if(i >= 4 && strcmp(&S[i-4], "E-N-D") == 0) break;

		if(isalpha(S[i]) || S[i] == '-') e++;
		else{
			if(result < e-s){
				result = e-s;
				re = e;
				rs = s;
			}
			s = e = i+1;
		}
	}
	for(int i=rs; i<re; i++){
		if(isupper(S[i])) putchar(S[i]-'A'+'a');
		else putchar(S[i]);
	}
}