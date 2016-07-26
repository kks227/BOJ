#include <cstdio>
#include <cmath>
using namespace std;

int main(){

	int T, N;
	double result;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		result = 0;
		for(int i=2; i<=N; i++)
			result += log10(i);
		printf("%d\n", 1+(int)result);
	}

	return 0;
}