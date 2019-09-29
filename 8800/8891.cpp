#include <cstdio>
using namespace std;

inline void N2C(int n, int &x, int &y){
	int p = 1, q = 0;
	while(1){
		q += p;
		if(n <= q) break;
		++p;
	}
	int r = n - q + p;
	x = r;
	y = p - r + 1;
}

inline int C2N(int x, int y){
	int p = x + y - 1;
	return p*(p-1)/2 + x;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int n1, n2, x1, y1, x2, y2;
		scanf("%d %d", &n1, &n2);
		N2C(n1, x1, y1);
		N2C(n2, x2, y2);
		printf("%d\n", C2N(x1+x2, y1+y2));
	}
}