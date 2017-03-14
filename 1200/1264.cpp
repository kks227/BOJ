#include <cstdio>
using namespace std;

int main(){
	while(1){
		char S[256];
		gets(S);
		if(S[0] == '#') break;

		int cnt = 0;
		for(int i=0; S[i]; i++){
			char c = S[i] - (S[i]>='a' ? 'a'-'A' : 0);
			if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') cnt++;
		}
		printf("%d\n", cnt);
	}
}