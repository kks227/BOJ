#include <cstdio>
using namespace std;

int main(){

	int N, R1, R, a, b, c;
	scanf("%d %d", &N, &R1);
	for(int i=1; i<N; i++){
		scanf("%d", &R);
		a = R1;
		b = R;
		while(b){
			c = a%b;
			a = b;
			b = c;
		}
		printf("%d/%d\n", R1/a, R/a);
	}

	return 0;
}