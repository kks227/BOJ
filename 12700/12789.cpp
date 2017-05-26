#include <cstdio>
#include <stack>
using namespace std;

int main(){
	int N, cnt = 1;
	scanf("%d", &N);
	stack<int> S;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		S.push(val);
		while(!S.empty() && S.top() == cnt){
			cnt++;
			S.pop();
		}
	}
	puts(S.empty() ? "Nice" : "Sad");
}