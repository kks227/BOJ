#include <cstdio>
using namespace std;

int main(){
	int N;
	long long result = 0;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		char c;
		scanf(" %c", &c);
		result = result*2 + (c == 'O');
	}
	printf("%lld\n", result);
}