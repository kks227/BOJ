#include <cstdio>
using namespace std;

int main(){
	int cnt[2] = {0};
	char S[256];
	gets(S);
	for(int i=0; S[i]; i++){
		if(S[i] == ':'){
			if(!S[i+1]) continue;
			if(S[i+1] == '-'){
				if(S[i+2] == ')') cnt[0]++;
				else if(S[i+2] == '(') cnt[1]++;
			}
		}
	}
	if(cnt[0]==0 && cnt[1]==0) puts("none");
	else if(cnt[0] == cnt[1]) puts("unsure");
	else if(cnt[0] > cnt[1]) puts("happy");
	else puts("sad");
}