#include <cstdio>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	bool map[397][397] = {0};
	for(int i=0; i<N; i++){
		for(int j=0; j<(N-i)*4-3; j++)
			map[i*2][i*2+j] = map[(N-1)*4-i*2][i*2+j] = map[i*2+j][i*2] = map[i*2+j][(N-1)*4-i*2] = true;
	}
	for(int i=0; i<N*4-3; i++){
		for(int j=0; j<N*4-3; j++)
			putchar(map[i][j]?'*':' ');
		puts("");
	}
}