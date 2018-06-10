#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair<long long, int> P;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	priority_queue<P, vector<P>, greater<P>> PQ;
	for(int i=0; i<N; i++){
		int A;
		scanf("%d", &A);
		PQ.push(P(A, A));
	}
	for(int i=0; i<M-1; i++){
		auto p = PQ.top();
		PQ.pop();
		PQ.push(P(p.first+p.second, p.second));
	}
	printf("%lld\n", PQ.top().first);
}