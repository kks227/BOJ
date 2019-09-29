#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int C;
	char S[201], map[201][201] = {'\0',};
	scanf("%d %s", &C, S);
	int L = strlen(S), R = L/C;
	for(int i = 0, k = 0; i < R; ++i)
		for(int j = 0; j < C; ++j, ++k)
			map[i][(i%2 ? C-j-1 : j)] = S[k];
	for(int i = 0; i < C; ++i)
		for(int j = 0; j < R; ++j)
			putchar(map[j][i]);
}