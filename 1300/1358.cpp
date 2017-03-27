#include <cstdio>
using namespace std;

int main(){
	int W, H, X, Y, P, result = 0;
	scanf("%d %d %d %d %d", &W, &H, &X, &Y, &P);
	for(int i=0; i<P; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		if(X <= x && x <= X+W && Y <= y && y <= Y+H || (X-x)*(X-x)+(Y+H/2-y)*(Y+H/2-y) <= H*H/4 || (X+W-x)*(X+W-x)+(Y+H/2-y)*(Y+H/2-y) <= H*H/4) result++;
	}
	printf("%d\n", result);
}