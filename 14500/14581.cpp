#include <cstdio>
using namespace std;

int main(){
	char S[21];
	scanf("%s", S);
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			putchar(':');
			printf("%s", i==1 && j==1 ? S : "fan");
			putchar(':');
		}
		puts("");
	}
}