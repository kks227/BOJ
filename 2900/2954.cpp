#include <cstdio>
using namespace std;

int main(){
	char C[101], P[101] = {0};
	gets(C);
	int i = 0, j = 0;
	while(C[i]){
		P[j++] = C[i];
		if(C[i]=='a' || C[i]=='e' || C[i]=='i' || C[i]=='o' || C[i]=='u') i+=3;
		else i++;
	}
	puts(P);
}