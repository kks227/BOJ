#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char S[501];
	scanf("%s", S);
	int N = strlen(S);
	for(int i=0; i<N;){
		if(S[i] == '.'){
			i++;
			continue;
		}
		int len = 0;
		for(int j=i; j<N && S[j]=='X'; j++) len++;
		if(len%2){
			puts("-1");
			return 0;
		}
		for(int j=0; j<len;){
			if(len-j >= 4)
				for(int k=0; k<4; k++) S[i+j++] = 'A';
			else
				for(int k=0; k<2; k++) S[i+j++] = 'B';
		}
		i += len;
	}
	puts(S);
}