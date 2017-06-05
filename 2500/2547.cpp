#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N;
		scanf("%d", &N);
		long long sum = 0;
		for(int i=0; i<N; i++){
			long long val;
			scanf("%lld", &val);
			sum = (sum + val) % N;
		}
		puts(sum ? "NO" : "YES");
	}
}