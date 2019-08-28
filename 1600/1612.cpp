#include <cstdio>
using namespace std;

int main(){
	int N, k = 0;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i){
		k = (10*k + 1) % N;
		if(k == 0){
			printf("%d\n", i);
			return 0;
		}
	}
	puts("-1");
}