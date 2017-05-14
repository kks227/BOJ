#include <cstdio>
#include <map>
using namespace std;

int main(){
	map<char, int> D;
	D['-'] = 0; D['\\'] = 1; D['('] = 2; D['@'] = 3;
	D['?'] = 4; D['>'] = 5; D['&'] = 6; D['%'] = 7; D['/'] = -1;
	while(1){
		char S[9];
		scanf("%s", S);
		if(S[0] == '#') break;

		int N = 0;
		for(int i=0; S[i]; i++) N = N*8 + D[S[i]];
		printf("%d\n", N);
	}
}