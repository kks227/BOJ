#include <cstdio>
using namespace std;

int main(){
	int X, Y;
	while(scanf("%d %d", &X, &Y) > 0){
		int Z = 100LL*Y/X;
		if(Z >= 99){
			puts("-1");
			continue;
		}
		long long deno = (Z+1LL)*X - 100LL*Y;
		printf("%lld\n", deno/(99-Z) + (deno%(99-Z)>0));
	}
}