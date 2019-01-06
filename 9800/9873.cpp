#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, x[1000], result = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", x+i);
	sort(x, x+N);
	for(int i = 0; i < N-1; ++i)
		for(int j = i+1; j < N; ++j)
			result += upper_bound(x, x+N, x[j]*3-x[i]*2) - lower_bound(x, x+N, x[j]*2-x[i]);
	printf("%d\n", result);
}