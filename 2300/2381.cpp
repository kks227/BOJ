#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e9;

int main(){
	int N, P1 = -MAX, P2 = MAX, Q1 = -MAX, Q2 = MAX;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int x, y, P, Q;
		scanf("%d %d", &x, &y);
		P = x + y;
		Q = y - x;
		P1 = max(P1, P); P2 = min(P2, P);
		Q1 = max(Q1, Q); Q2 = min(Q2, Q);
	}
	printf("%d\n", max(P1-P2, Q1-Q2));
}