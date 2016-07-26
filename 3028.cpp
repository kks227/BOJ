#include <cstdio>
using namespace std;

int main(){
	char S[51];
	scanf("%s", S);
	int next[3][3] = {1, 0, 2, 0, 2, 1, 2, 1, 0}, cur = 0;
	for(int i=0; S[i]; i++)
		cur = next[S[i]-'A'][cur];
	printf("%d\n", cur+1);
}