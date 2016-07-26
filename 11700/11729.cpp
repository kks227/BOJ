#include <cstdio>
using namespace std;

inline int C(int a, int b){
	for(int i=1; i<=3; i++)
		if(a!=i && b!=i) return i;
}

void Hanoi(int n, int from, int to){
	if(n == 0) return;
	int c = C(from, to);
	Hanoi(n-1, from, c);
	printf("%d %d\n", from, to);
	Hanoi(n-1, c, to);
}

int main(){
	int N;
	scanf("%d", &N);
	printf("%d\n", (1<<N)-1);
	Hanoi(N, 1, 3);
}