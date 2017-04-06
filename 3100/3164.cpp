#include <cstdio>
using namespace std;

inline long long cnt(int x, int y){
	if(x == 0 || y == 0) return 0;
	if(x < y) return cnt(y, x);
	return y/2LL*(y/2*2+1) + ((x-y)/2LL+(x-y)%2*(y%2))*y;
}

int main(){
	int X1, Y1, X2, Y2;
	scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2);
	printf("%lld\n", cnt(X2, Y2)-cnt(X1, Y2)-cnt(X2, Y1)+cnt(X1, Y1));
}