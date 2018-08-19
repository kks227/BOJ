#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int N, M;
	scanf("%d %d", &N, &M);
	priority_queue<long long, vector<long long>, greater<long long>> PQ;
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		PQ.push(val);
	}
	for(int i=0; i<M; i++){
		long long a = PQ.top(); PQ.pop();
		long long b = PQ.top(); PQ.pop();
		PQ.push(a+b);
		PQ.push(a+b);
	}
	long long result = 0;
	for(int i=0; i<N; i++){
		result += PQ.top();
		PQ.pop();
	}
	printf("%lld\n", result);
}