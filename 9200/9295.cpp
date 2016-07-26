#include <cstdio>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		int A, B;
		scanf("%d %d", &A, &B);
		printf("Case %d: %d\n", t, A+B);
	}
}