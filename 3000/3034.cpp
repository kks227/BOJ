#include <cstdio>
using namespace std;

int main(){

	int N, W, H, n, size;
	scanf("%d %d %d", &N, &W, &H);
	size = W*W + H*H;
	for(int i=0; i<N; i++){
		scanf("%d", &n);
		puts(n*n<=size?"DA":"NE");
	}

	return 0;
}