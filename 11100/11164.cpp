#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int R, C;
		scanf("%d %d", &R, &C);
		char dummy;
		for(int i = 0; i < R*C; ++i)
			scanf(" %c", &dummy);
		if(R > C) swap(R, C);
		if(R == 1) printf("%d\n", (C-1)*2);
		else printf("%d\n", R*C + R*C%2);
	}
	puts("LOL");
}