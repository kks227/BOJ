#include <cstdio>
using namespace std;

int main(){
	while(1){
		char S[1000];
		gets(S);
		if(S[0] == '#') break;
		int sum = 0;
		for(int i=0; S[i]; i++)
			if(S[i] != ' ') sum += (i+1)*(S[i]-'A'+1);
		printf("%d\n", sum);
	}
}