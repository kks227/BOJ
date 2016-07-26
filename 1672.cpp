#include <cstdio>
using namespace std;

int main(){
	int N, AtoN[26], map[4][4]={
		{0, 2, 0, 1}, {2, 1, 3, 0}, {0, 3, 2, 1}, {1, 0, 1, 3}
	};
	char c[1000001], NtoA[4] = {'A', 'G', 'C', 'T'};
	AtoN[0] = 0;
	AtoN[6] = 1;
	AtoN[2] = 2;
	AtoN[19] = 3;
	scanf("%d\n%s", &N, c);
	for(int i=N-2; i>=0; i--)
		c[i] = NtoA[ map[AtoN[c[i]-'A']][AtoN[c[i+1]-'A']] ];
	putchar(c[0]);
}