#include <cstdio>
using namespace std;

int main(){
	int N, t = 0;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int A, B;
		scanf("%d %d", &A, &B);
		if(t%(A+B) < B) t = t/(A+B)*(A+B)+B;
		t++;
	}
	printf("%d\n", t);
}