#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	char S[101];
	scanf("%s", S);
	int N = strlen(S), R, C;
	for(R=1; N%R!=0 || R<N/R; R++);
	C = N/R;
	for(int c=0; c<C; c++)
		for(int r=0; r<R; r++)
			putchar(S[r*C+c]);
}