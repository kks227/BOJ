#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int N;
	priority_queue<long long, vector<long long>, greater<long long>> PQ;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int A;
		scanf("%d", &A);
		PQ.push(A);
	}
	long long result = 0;
	for(int i = 0; i < N-1; ++i){
		long long A = PQ.top(); PQ.pop();
		long long B = PQ.top(); PQ.pop();
		result += A*B;
		PQ.push(A+B);
	}
	printf("%lld\n", result);
}