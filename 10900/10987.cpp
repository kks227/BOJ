#include <cstdio>
using namespace std;

int main(){
	int result = 0;
	char word[101];
	scanf("%s", word);
	for(int i=0; word[i]; i++)
		result += (word[i]=='a' || word[i]=='e' || word[i]=='i' || word[i]=='o' || word[i]=='u');
	printf("%d\n", result);
}