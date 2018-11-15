#include <cstdio>
using namespace std;

int main(){
	int N, R, C;
	scanf("%d %d %d", &N, &R, &C);
	--R; --C;
	for(int i = 0; i < N; ++i){
		for(int j = 0; j < N; ++j)
			putchar((i+j)%2 == (R+C)%2 ? 'v' : '.');
		puts("");
	}
}