#include <cstdio>
using namespace std;

int main(){
	int N;
	long long sum = 0, result = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		result += sum*val;
		sum += val;
	}
	printf("%lld\n", result);
}