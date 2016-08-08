#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char P[30001], K[30001];
	gets(P);
	scanf("%s", K);
	int len = strlen(K);
	for(int i=0; P[i]; i++){
		if(P[i] == ' ') putchar(' ');
		else putchar((P[i]-'a'+25-K[i%len]+'a')%26+'a');
	}
}