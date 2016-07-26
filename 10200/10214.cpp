#include <cstdio>
using namespace std;

int main(){

	int T, Y, K, y, k;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		Y = K = 0;
		for(int i=0; i<9; i++){
			scanf("%d %d", &y, &k);
			Y += y;
			K += k;
		}
		if(Y==K) puts("Draw");
		else if(Y>K) puts("Yonsei");
		else puts("Korea");
	}

	return 0;
}