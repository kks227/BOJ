#include <cstdio>
using namespace std;

int main(){
	int N, i;
	scanf("%d", &N);
	for(i=1; i*i<=N; i++);
	printf("%d\n", i-1);
}