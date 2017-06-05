#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	while(1){
		char S[21];
		scanf("%s", S);
		if(strcmp(S, "end") == 0) break;

		bool used[26] = {0}, vused = false, vowel[26] = {0}, fail = false;
		vowel[0] = vowel[4] = vowel[8] = vowel[14] = vowel[20] = true;
		for(int i=0; S[i]; i++){
			used[S[i]-'a'] = true;
			if(vowel[S[i]-'a']) vused = true;
			if(i > 0 && S[i] == S[i-1] && S[i] != 'e' && S[i] != 'o') fail = true;
			if(i > 1 && vowel[S[i]-'a'] == vowel[S[i-1]-'a'] && vowel[S[i]-'a'] == vowel[S[i-2]-'a']) fail = true;
		}
		if(!vused) fail = true;
		printf("<%s> is %sacceptable.\n", S, fail ? "not " : "");
	}
}