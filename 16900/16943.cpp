#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

int main(){
	int A, B, D = 0, d[10], p[10];
	long long C = -1;
	scanf("%d %d", &A, &B);
	while(A > 0){
		d[D++] = A%10;
		A /= 10;
	}
	iota(p, p+D, 0);
	do{
		if(d[p[0]] != 0){
			long long temp = 0;
			for(int i = 0; i < D; ++i)
				temp = temp*10 + d[p[i]];
			if(temp <= B) C = max(C, temp);
		}
	}while(next_permutation(p, p+D));
	printf("%lld\n", C);
}