#include <cstdio>
#include <cmath>
#include <vector>
#include <queue>
#include <functional>
#include <utility>
using namespace std;
typedef pair<int, bool> P;

int main(){
	priority_queue<P, vector<P>, greater<P>> pq;
	int N, x;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%d", &x);
		if(x) pq.push(P(abs(x), x>0));
		else if(pq.empty()) printf("0\n");
		else{
			printf("%d\n", pq.top().first*(pq.top().second?1:-1));
			pq.pop();
		}
	}
}