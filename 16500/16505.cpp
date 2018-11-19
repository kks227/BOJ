#include <cstdio>
using namespace std;

bool map[1024][1024];

void draw(int n, int r, int c){
	if(n == 0){
		map[r][c] = true;
		return;
	}
	int k = 1 << n-1;
	draw(n-1, r, c);
	draw(n-1, r+k, c);
	draw(n-1, r, c+k);
}

int main(){
	int N;
	scanf("%d", &N);
	draw(N, 0, 0);
	for(int i = 0; i < 1<<N; ++i){
		for(int j = 0; j < (1<<N)-i; ++j)
			putchar(map[i][j] ? '*' : ' ');
		puts("");
	}
}