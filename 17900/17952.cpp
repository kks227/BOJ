#include <cstdio>
#include <utility>
using namespace std;
const int MAX = 1000000;
typedef pair<int, int> P;

int main(){
	int N, t = 0, result = 0;
	P S[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int op;
		scanf("%d", &op);
		if(op == 1){
			int A, T;
			scanf("%d %d", &A, &T);
			S[t++] = P(A, T);
		}
		if(t > 0){
			if(--S[t-1].second == 0) result += S[--t].first;
		}
	}
	printf("%d\n", result);
}