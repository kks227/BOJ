#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
#include <functional>
using namespace std;
typedef tuple<int, int, int> T;

int main(){
	int N, S, M;
	priority_queue<T, vector<T>, greater<T>> PQ;
	scanf("%d %d %d", &N, &S, &M);
	for(int i=0; i<M; i++){
		int t;
		scanf("%d", &t);
		PQ.push(T(0, i+1, t));
	}
	for(int i=0; i<N-S-1; i++){
		T t = PQ.top();
		PQ.pop();
		get<0>(t) += get<2>(t);
		PQ.push(t);
	}
	printf("%d\n", get<1>(PQ.top()));
}