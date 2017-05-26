#include <cstdio>
using namespace std;

int main(){
	int N, result = 0;
	scanf("%d", &N);
	for(int i=1; i<=N; i++){
		for(int j=1; j*j<=i; j++)
			if(i%j == 0) result++;
	}
	printf("%d\n", result);
}