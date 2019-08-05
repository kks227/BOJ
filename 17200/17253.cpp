#include <cstdio>
using namespace std;

int main(){
	unsigned long long N, p = 1;
	scanf("%llu", &N);
	if(N == 0){
		puts("NO");
		return 0;
	}
	for(; p*3 <= N && p*3 >= p; p *= 3);
	for(; p > 0; p /= 3)
		if(N >= p) N -= p;
	puts(N ? "NO" : "YES");
}