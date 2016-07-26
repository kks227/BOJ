#include <cstdio>
using namespace std;

int main(){
	int N, sum = 0;
	while(scanf("%d", &N) > 0) sum += N;
	printf("%d\n", sum);
}