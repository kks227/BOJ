#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100;

int main(){
	int R, C, map[2][MAX][MAX] = {0,};
	scanf("%d %d", &C, &R);
	for(int i = 0; i < R; ++i)
		for(int j = 0; j < C; ++j)
			scanf("%d", &map[0][i][j]);
	for(int i = 0; i < C; ++i)
		for(int j = 0; j < R; ++j)
			scanf("%d", &map[1][R-j-1][i]);
	if(memcmp(map[0], map[1], sizeof(map[0])) != 0){
		puts("|>___/|     /}");
		puts("| O O |    / }");
		puts("( =0= )\"\"\"\"  \\");
		puts("| ^  ____    |");
		puts("|_|_/    ||__|");
	}
	else{
		puts("|>___/|        /}");
		puts("| O < |       / }");
		puts("(==0==)------/ }");
		puts("| ^  _____    |");
		puts("|_|_/     ||__|");
		return 0;
	}
}