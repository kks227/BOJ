#include <cstdio>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main(){
	int N, mid;
	scanf("%d", &N);
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	for(int i=0; i<N; i++){
		int M;
		scanf("%d", &M);
		if(i%2){
			if(mid > M){
				minHeap.push(mid);
				maxHeap.push(M);
			}
			else{
				maxHeap.push(mid);
				minHeap.push(M);
			}
			printf("%d\n", maxHeap.top());
		}
		else{
			if(maxHeap.size() && maxHeap.top() > M){
				mid = maxHeap.top();
				maxHeap.pop();
				maxHeap.push(M);
			}
			else if(minHeap.size() && minHeap.top() < M){
				mid = minHeap.top();
				minHeap.pop();
				minHeap.push(M);
			}
			else mid = M;
			printf("%d\n", mid);
		}
	}
}