#include <cstdio>
using namespace std;

int gcd(int p, int q){
	while(q){
		int r = p % q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	int N, M, G;
	scanf("%d:%d", &N, &M);
	G = gcd(N, M);
	printf("%d:%d\n", N/G, M/G);
}