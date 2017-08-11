#include <cstdio>
using namespace std;

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	printf("%d %d\n", K/M, K%M);
}