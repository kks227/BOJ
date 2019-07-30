#include <cstdio>
#include <unordered_map>
using namespace std;
const int MAX = 100;

int main(){
	unordered_map<char, char> H;
	H['.'] = '.'; H['O'] = 'O'; H['-'] = '|';
	H['|'] = '-'; H['/'] = '\\'; H['\\'] = '/';
	H['^'] = '<'; H['<'] = 'v'; H['v'] = '>'; H['>'] = '^';
	int R, C;
	char map[MAX][MAX];
	scanf("%d %d\n", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j)
			map[i][j] = getchar();
		getchar();
	}
	for(int i = 0; i < C; ++i){
		for(int j = 0; j < R; ++j)
			putchar(H[map[j][C-1-i]]);
		puts("");
	}
}