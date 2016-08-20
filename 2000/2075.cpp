#include <cstdio>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

int main(){
	int N;
	priority_queue<int, vector<int>, greater<int>> PQ;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			int val;
			scanf("%d", &val);
			PQ.push(val);
			if(i > 0) PQ.pop();
		}
	}
	printf("%d\n", PQ.top());
}