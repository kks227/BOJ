#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char S[10];
		scanf("%s", S);
		if(S[0] == 'P') puts("skipped");
		else{
			int A = 0, B = 0, i;
			for(i=0; S[i]!='+'; i++)
				A = A*10 + S[i]-'0';
			for(i++; S[i]; i++)
				B = B*10 + S[i]-'0';
			printf("%d\n", A+B);
		}
	}
}