#include <cstdio>
using namespace std;

int main(){
	int N, val;
	long long result = 0;
	scanf("%d", &N);
	for(int i = 0; i < N*N; ++i){
		scanf("%d", &val);
		result += val;
	}
	printf("%lld\n", result);
}