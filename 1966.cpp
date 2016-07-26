#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
typedef pair<int, int> P;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		scanf("%d %d", &N, &M);
		queue<P> Q;
		priority_queue<P> PQ;
		for(int i=0; i<N; i++){
			int cost;
			scanf("%d", &cost);
			Q.push(P(cost, i));
			PQ.push(P(cost, i));
		}
		for(int i=1; ; i++){
			while(Q.front().first < PQ.top().first){
				Q.push(Q.front());
				Q.pop();
			}
			if(Q.front().second == M){
				printf("%d\n", i);
				break;
			}
			Q.pop();
			PQ.pop();
		}
	}
}