#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int c;
	while((c=getchar()) != -1){
		if(isupper(c)) putchar((c-'A'+13)%26+'A');
		else if(islower(c)) putchar((c-'a'+13)%26+'a');
		else putchar(c);
	}
}