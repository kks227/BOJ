#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int A, B, M, N = 0;
	scanf("%d %d %d", &A, &B, &M);
	for(int i=0; i<M; i++){
		int D;
		scanf("%d", &D);
		N = N*A + D;
	}
	stack<int> S;
	while(N){
		S.push(N%B);
		N /= B;
	}
	while(!S.empty()){
		printf("%d ", S.top());
		S.pop();
	}
}