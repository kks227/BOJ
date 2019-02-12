#include <cstdio>
using namespace std;

int main(){
	int R, B;
	scanf("%d %d", &R, &B);
	for(int i = 1; ; ++i){
		if(B%i) continue;
		int w1 = B/i, h1 = i, w2 = w1+2, h2 = h1+2;
		if((w2+h2-2)*2 == R){
			printf("%d %d\n", w2, h2);
			return 0;
		}
	}
}