#include <cstdio>
using namespace std;

int main(){
	int N, y[100000], K;
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", y+i);
	scanf("%d", &K);
	if(K == y[0]){
		puts("T");
		return 0;
	}

	for(int i=1; i<N; i++){
		if(1LL*K*i <= y[i-1] && y[i] <= 1LL*K*(i+1)){
			puts("T");
			return 0;
		}
	}
	puts("F");
}