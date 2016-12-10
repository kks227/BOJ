#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	while(1){
		char S[251];
		gets_s(S);
		if(S[0] == '#') break;

		bool c[26] = {0};
		for(int i=0; S[i]; i++){
			if(islower(S[i])) S[i] -= 32;
			if(isupper(S[i])) c[S[i]-'A'] = true;
		}
		int result = 0;
		for(int i=0; i<26; i++)
			result += c[i];
		printf("%d\n", result);
	}
}