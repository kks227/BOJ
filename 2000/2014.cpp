#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int K, N, P[100];
	priority_queue<int, vector<int>, greater<int>> PQ;
	scanf("%d %d", &K, &N);
	for(int i=0; i<K; i++){
		scanf("%d", P+i);
		PQ.push(P[i]);
	}
	int prev = -1;
	for(int i=0; i<N-1; i++){
		int curr = PQ.top();
		PQ.pop();
		for(int j=0; j<K; j++){
			long long temp = 1LL * curr * P[j];
			if(temp < 1LL<<31) PQ.push(temp);
			else break;
		}
		prev = curr;
		while(prev == PQ.top()) PQ.pop();
	}
	printf("%d\n", PQ.top());
}