#include <cstdio>
#include <stack>
#include <algorithm>
using namespace std;
const int MAX = 30000;

int main(){
	int N, H[MAX], result = 0;
	scanf("%d", &N);
	stack<int> S;
	for(int i = 0; i < N; ++i){
		scanf("%d", H+i);
		while(!S.empty() && H[S.top()] <= H[i]){
			result = max(i-S.top()-1, result);
			S.pop();
		}
		S.push(i);
	}
	while(!S.empty()){
		result = max(N-S.top()-1, result);
		S.pop();
	}
	printf("%d\n", result);
}