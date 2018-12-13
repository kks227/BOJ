#include <cstdio>
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
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int N, val[100];
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", val+i);
		long long result = 0;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < i; ++j)
				result += gcd(val[i], val[j]);
		printf("%lld\n", result);
	}
}