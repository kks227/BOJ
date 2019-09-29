#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[4] = {1, 0, -1, 0};
const int coff[4] = {0, -1, 0, 1};
const int MAX = 101;

int main(){
	int N, d = 0, r = MAX/2, c = MAX/2, r1 = r, r2 = r, c1 = c, c2 = c;
	bool visited[MAX][MAX] = {false,};
	visited[r][c] = true;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char k;
		scanf(" %c", &k);
		if(k == 'F'){
			r += roff[d];
			c += coff[d];
			visited[r][c] = true;
			r1 = min(r1, r); c1 = min(c1, c);
			r2 = max(r2, r); c2 = max(c2, c);
		}
		else if(k == 'L') d = (d+3)%4;
		else d = (d+1)%4;
	}
	for(int i = r1; i <= r2; ++i){
		for(int j = c1; j <= c2; ++j)
			putchar(visited[i][j] ? '.' : '#');
		puts("");
	}
}