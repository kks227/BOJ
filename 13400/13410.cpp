#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	for(int i=1; i<=K; i++){
		int n = N*i, m = 0;
		while(n){
			m = m*10 + n%10;
			n /= 10;
		}
		result = max(result, m);
	}
	printf("%d\n", result);
}