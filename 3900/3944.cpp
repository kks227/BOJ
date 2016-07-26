#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int B, result = 0;
		scanf("%d", &B);
		getchar();
		while(1){
			char c = getchar();
			if(c == '\n') break;
			result = (result*B + c-'0') % (B-1);
		}
		printf("%d\n", result);
	}
}