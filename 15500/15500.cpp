#include <cstdio>
#include <stack>
using namespace std;
const int MAX = 12345;

int main(){
	int N, K = 0, result[MAX][2], pos[124];
	stack<int> S[3];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int a;
		scanf("%d", &a);
		pos[a] = 0;
		S[0].push(a);
	}

	for(int i=N; i>0; K++){
		int s = pos[i];
		result[K][0] = s+1;
		if(S[s].top() == i){
			result[K][1] = 3;
			pos[i] = 2;
			S[2].push(S[s].top());
			S[s].pop();
			i--;
		}
		else{
			result[K][1] = (!s)+1;
			pos[S[s].top()] = !s;
			S[!s].push(S[s].top());
			S[s].pop();
		}
	}
	printf("%d\n", K);
	for(int i=0; i<K; i++)
		printf("%d %d\n", result[i][0], result[i][1]);
}