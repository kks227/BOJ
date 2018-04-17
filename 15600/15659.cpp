#include <cstdio>
#include <stack>
#include <functional>
#include <algorithm>
using namespace std;
const int INF = 1e9 + 1;

int N, infix[21], cnt[4], r1 = -INF, r2 = INF;
function<int(int, int)> func[4] = {
	[](int a, int b){ return a+b; },
	[](int a, int b){ return a-b; },
	[](int a, int b){ return a*b; },
	[](int a, int b){ return (a>0 ? a/b : -a/b*-1); }
};

void dfs(int pos = 0){
	if(pos == N-1){
		int postfix[21], j = 0;
		stack<int> S;
		for(int i=0; i<N*2-1; i++){
			if(infix[i] < INF) postfix[j++] = infix[i];
			else{
				int op = infix[i] - INF;
				if(S.empty()) S.push(op);
				else if(S.top() < 2 && op >= 2) S.push(op);
				else{
					while(!S.empty() && !(S.top() < 2 && op >= 2)){
						postfix[j++] = S.top() + INF;
						S.pop();
					}
					S.push(op);
				}
			}
		}
		while(!S.empty()){
			postfix[j++] = S.top() + INF;
			S.pop();
		}

		for(j=0; j<2*N-1; j++){
			if(postfix[j] < INF) S.push(postfix[j]);
			else{
				int b = S.top(); S.pop();
				int a = S.top(); S.pop();
				S.push(func[postfix[j]-INF](a, b));
			}
		}
		r1 = max(r1, S.top());
		r2 = min(r2, S.top());
		return;
	}

	for(int i=0; i<4; i++){
		if(cnt[i] == 0) continue;
		cnt[i]--;
		infix[pos*2+1] = i + INF;
		dfs(pos+1);
		cnt[i]++;
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", infix+i*2);
	for(int i=0; i<4; i++)
		scanf("%d", cnt+i);
	dfs();
	printf("%d\n%d\n", r1, r2);
}