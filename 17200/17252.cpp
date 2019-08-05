#include <cstdio>
using namespace std;

int main(){
	int N, p = 1;
	scanf("%d", &N);
	if(N == 0){
		puts("NO");
		return 0;
	}
	for(; p*3LL <= N; p *= 3);
	for(; p > 0; p /= 3)
		if(N >= p) N -= p;
	puts(N ? "NO" : "YES");
}