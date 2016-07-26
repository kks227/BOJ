#include <cstdio>
using namespace std;

int main(){

	int T;
	char S[51];
	int par, i;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%s", S);
		par = 0;
		for(i=0; S[i]; i++){
			if(S[i] == '(') par++;
			else if(par == 0) break;
			else par--;
		}
		printf("%s\n", (S[i] || par)?"NO":"YES");
	}

	return 0;
}