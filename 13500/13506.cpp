#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1<<20;

int main(){
	char S[MAX];
	scanf("%s", S);
	int L = strlen(S), fail[MAX] = {0};
	for(int i=1, j=0; i<L; i++){
		while(j > 0 && S[i] != S[j]) j = fail[j-1];
		if(S[i] == S[j]) fail[i] = ++j;
	}
	bool flag[MAX] = {0};
	for(int i=0; i<L-1; i++)
		if(fail[i] > 0) flag[fail[i]] = true;
	for(int i=L-1; i>0 && fail[i]>0; i=fail[i]-1){
		if(flag[fail[i]]){
			S[fail[i]] = '\0';
			printf("%s\n", S);
			return 0;
		}
	}
	puts("-1");
}