#include <cstdio>
#include <cctype>
using namespace std;

int main(){
	int N, A = 0, B = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a < b) B++;
		else if(a > b) A++;
	}
	printf("%d %d\n", A, B);
}