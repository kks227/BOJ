#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 5000001;

int main(){
	int F, A, B, result = 0;
	scanf("%d %d %d", &F, &A, &B);
	bool visited[2][MAX] = {true,};
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		int curr = Q.front() % MAX;
		bool drunk = Q.front() / MAX;
		Q.pop();
		result = max(curr, result);

		if(!drunk && !visited[true][curr/2]){
			visited[true][curr/2] = true;
			Q.push(MAX + curr/2);
		}
		if(curr+A <= F && !visited[drunk][curr+A]){
			visited[drunk][curr+A] = true;
			Q.push(drunk*MAX + curr+A);
		}
		if(curr+B <= F && !visited[drunk][curr+B]){
			visited[drunk][curr+B] = true;
			Q.push(drunk*MAX + curr+B);
		}
	}
	printf("%d\n", result);
}