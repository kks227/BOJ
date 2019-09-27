#include <cstdio>
using namespace std;

int main(){
	int R, C;
	scanf("%d %d", &R, &C);
	for(int i = 0; i < R; ++i){
		for(int j = 0; j < C; ++j)
			putchar((i+j)%2 ? '.' : '*');
		puts("");
	}
}