#include <cstdio>
using namespace std;

int main(){
	char S[1000001];
	scanf("%s", S);
	int pcnt = 0;
	for(int i=0; S[i]; i++){
		if(S[i] == 'P') pcnt++;
		else{
			if(pcnt >= 2 && S[i+1] == 'P'){
				pcnt--;
				i++;
			}
			else{
				puts("NP");
				return 0;
			}
		}
	}
	puts(pcnt == 1 ? "PPAP" : "NP");
}