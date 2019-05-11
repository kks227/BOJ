#include <cstdio>
using namespace std;

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j){
			int r, g, b;
			scanf("%d %d %d", &r, &g, &b);
			int val = 2126*r + 7152*g + 722*b;
			if (val < 510000) putchar('#');
			else if (val < 1020000) putchar('o');
			else if (val < 1530000) putchar('+');
			else if (val < 2040000) putchar('-');
			else putchar('.');
		}
		puts("");
	}
}