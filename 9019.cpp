#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;

inline int D(int n){ return n*2%10000; }
inline int S(int n){ return (n+9999)%10000; }
inline int L(int n){ return n*10%10000 + n/1000; }
inline int R(int n){ return n*1000%10000 + n/10; }

int main(){
	int T;
	scanf("%d", &T);
	int (*func[4])(int) = {D, S, L, R};
	char c[4] = {'D', 'S', 'L', 'R'};

	for(int t=0; t<T; t++){
		int A, B;
		scanf("%d %d", &A, &B);
		int prev[10000];
		memset(prev, -1, sizeof(prev));
		prev[A] = A;
		char op[10000];
		memset(op, -1, sizeof(op));
		queue<int> Q;
		Q.push(A);

		while(prev[B] == -1){
			int cur = Q.front();
			Q.pop();
			for(int i=0; i<4; i++){
				int next = func[i](cur);
				if(prev[next] == -1){
					prev[next] = cur;
					op[next] = c[i];
					Q.push(next);
				}
			}
		}

		stack<char> S;
		int cur = B;
		while(prev[cur] != cur){
			S.push(op[cur]);
			cur = prev[cur];
		}
		while(!S.empty()){
			putchar(S.top());
			S.pop();
		}
		puts("");
	}
}