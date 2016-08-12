#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", (n*n*n*n+6*n*n*n+11*n*n+6*n)/8);
	}
}