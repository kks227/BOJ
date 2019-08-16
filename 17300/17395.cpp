#include <cstdio>
using namespace std;
const int MAX_B = 60;

int main(){
	long long x;
	int N, bcnt = 0;;
	scanf("%lld %d", &x, &N);
	for(int i = 0; i < MAX_B; ++i)
		if(x & 1LL<<i) ++bcnt;
	if(bcnt < N) puts("-1");
	else{
		for(int i = 1, j = MAX_B-1; i < N; ++i){
			for(; !(x & 1LL<<j); --j);
			x -= 1LL<<j;
			printf("%lld ", x);
		}
		puts("0");
	}
}