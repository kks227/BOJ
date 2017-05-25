#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int B;
		scanf("%d\n", &B);
		printf("Case #%d: ", t);
		for(int i=0; i<B; i++){
			int c = 0;
			for(int j=0; j<8; j++)
				c = c*2 + (getchar()=='I');
			putchar(c);
		}
		puts("");
	}
}