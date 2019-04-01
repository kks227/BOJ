#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N;
		char c;
		scanf("%d %c", &N, &c);
		for(int i = 0; i < N; ++i)
			putchar(c);
		puts("");
	}
}