#include <cstdio>
using namespace std;

int main(){
	int A, B, M;
	scanf("%d %d %d", &A, &B, &M);
	bool flag = false;
	for(int i=0; i<M; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a%2 && b%2) flag = true;
	}
	if(A%2 == 0 || B%2 == 0) printf("%d\n", A/2 + B/2);
	else printf("%d\n", A/2 + B/2 + flag);
}