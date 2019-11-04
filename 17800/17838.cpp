#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		char S[10001];
		scanf("%s", S);
		if(strlen(S) != 7) puts("0");
		else printf("%d\n", S[0]==S[1]&&S[0]==S[4]&&S[0]!=S[2]&&S[2]==S[3]&&S[2]==S[5]&&S[2]==S[6]);
	}
}