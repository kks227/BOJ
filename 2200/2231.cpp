#include <cstdio>
using namespace std;

int dsum(int n){
	if(n == 0) return 0;
	return n%10 + dsum(n/10);
}

int main(){
	int N, result = -1;
	scanf("%d", &N);
	for(int i=1000000; i>=1; i--)
		if(i+dsum(i) == N) result = i;
	printf("%d\n", result!=-1 ? result : 0);
}