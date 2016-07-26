#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int N, P, result = 0;
	scanf("%d %d", &N, &P);
	stack<int> S[6];
	for(int i=0; i<N; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		while(!S[a].empty() && S[a].top()>b){
			result++;
			S[a].pop();
		}
		if(S[a].empty() || S[a].top()<b){
			result++;
			S[a].push(b);
		}
	}
	printf("%d\n", result);
}