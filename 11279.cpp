#include <cstdio>
#include <queue>
using namespace std;

int main(){
	priority_queue<int> pq;
	int N, x;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		if(x) pq.push(x);
		else if(pq.empty()) printf("0\n");
		else{
			printf("%d\n", pq.top());
			pq.pop();
		}
	}
}