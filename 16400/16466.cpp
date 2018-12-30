#include <cstdio>
using namespace std;

int main(){
	int N;
	bool sold[1000002] = {true,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int A;
		scanf("%d", &A);
		sold[A] = true;
	}
	for(int i = 1; ; ++i){
		if(!sold[i]){
			printf("%d\n", i);
			return 0;
		}
	}
}