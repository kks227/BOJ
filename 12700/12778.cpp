#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int M;
		char C;
		scanf("%d %c", &M, &C);
		if(C == 'C'){
			for(int i=0; i<M; i++){
				char c;
				scanf(" %c", &c);
				printf("%d ", c-'A'+1);
			}
		}
		else{
			for(int i=0; i<M; i++){
				int n;
				scanf("%d", &n);
				printf("%c ", n-1+'A');
			}
		}
		puts("");
	}
}