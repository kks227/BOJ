#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int INF = 1e9;

inline int operate(int x, char op, int y){
	if(op == '+') return x + y;
	if(op == '-') return x - y;
	if(op == '*') return x * y;
	return ((x < 0) != (y < 0) ? -1 : 1) * (abs(x) / abs(y));
}

int main(){
	int A[3];
	char op[2];
	scanf("%d", A);
	for(int i = 0; i < 2; ++i)
		scanf(" %c %d", op+i, A+i+1);

	int r1 = INF, r2 = -INF;
	for(int k = 0; k < 2; ++k){
		int x, y;
		if(k == 0){
			x = A[0];
			y = operate(A[1], op[1], A[2]);
		}
		else{
			x = operate(A[0], op[0], A[1]);
			y = A[2];
		}
		int temp = operate(x, op[k], y);
		r1 = min(temp, r1);
		r2 = max(temp, r2);
	}
	printf("%d\n%d\n", r1, r2);
}