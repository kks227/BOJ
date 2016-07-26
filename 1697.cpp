#include <cstdio>
#include <queue>
using namespace std;
const int PIVOT = 150000;

queue<int> Q;
bool visited[PIVOT*2+1];

inline void pushIf(int k){
	if(k>=-PIVOT && k<=PIVOT && !visited[k+PIVOT]){
		Q.push(k);
		visited[k+PIVOT] = true;
	}
}

int main(){
	int N, K;
	scanf("%d %d", &N, &K);
	Q.push(N);
	visited[N+PIVOT] = true;

	int result = 0;
	while(!visited[K+PIVOT]){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			int cur = Q.front();
			Q.pop();
			pushIf(cur-1);
			pushIf(cur+1);
			pushIf(cur*2);
		}
		result++;
	}
	printf("%d\n", result);
}