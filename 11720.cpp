#include <cstdio>
using namespace std;

int main(){
	int N, sum = 0;
	scanf("%d", &N);
	for(int i=N-1; i>=0; i--){
		scanf("%1d", &N);
		sum += N;
	}
	printf("%d\n", sum);
}