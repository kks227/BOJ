#include <cstdio>
using namespace std;

int main(){
	int N, result = 0, cost[6] = {500, 100, 50, 10, 5, 1};
	scanf("%d", &N);
	N = 1000 - N;
	for(int i=0; i<6; i++){
		result += N / cost[i];
		N %= cost[i];
	}
	printf("%d\n", result);
}