#include <cstdio>
using namespace std;

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int n;
		scanf("%d", &n);
		if(n==1) sum++;
	}
	printf("Junhee is %scute!\n", sum>N/2?"":"not ");
}