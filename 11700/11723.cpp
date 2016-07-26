#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	int M, S = 0, x;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		char op[7];
		scanf("%s", op);
		if(strcmp(op, "add") == 0){
			scanf("%d", &x);
			S |= 1 << --x;
		}
		else if(strcmp(op, "remove") == 0){
			scanf("%d", &x);
			S &= ~(1 << --x);
		}
		else if(strcmp(op, "check") == 0){
			scanf("%d", &x);
			printf("%d\n", (S & 1 << --x) ? 1 : 0);
		}
		else if(strcmp(op, "toggle") == 0){
			scanf("%d", &x);
			if(S & 1 << --x) S &= ~(1 << x);
			else S |= 1 << x;
		}
		else if(strcmp(op, "all") == 0) S = (1 << 20) - 1;
		else S = 0;
	}
}