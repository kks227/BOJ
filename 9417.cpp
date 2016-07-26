#include <cstdio>
#include <algorithm>
using namespace std;

int gcd(int m, int n){
	int temp;
	while(n){
		temp = m%n;
		m = n;
		n = temp;
	}
	return m;
}

int main(){

	int T, N, val[100], result;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		N = 0;
		while(1){
			scanf("%d",val+N);
			N++;
			if(getchar() == '\n') break;
		}
		result = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<i; j++)
				result = max(result, gcd(val[i], val[j]));
		printf("%d\n", result);
	}

	return 0;
}