#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	int N, x[20], y[20], result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", x+i, y+i);
	for(int i=0; i<N; i++)
		result += abs(x[i]-x[(i+1)%N]) + abs(y[i]-y[(i+1)%N]);
	printf("%d\n", result);
}