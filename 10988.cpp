#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char word[101];
	scanf("%s", word);
	int len = strlen(word);
	for(int i=0; i<len/2; i++)
		if(word[i] != word[len-i-1]){
			puts("0");
			return 0;
		}
	puts("1");
}