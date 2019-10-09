#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 360;
const int MAX_N = 10;

int main(){
	int N, K, A[MAX_N];
	scanf("%d %d", &N, &K);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);

	queue<int> Q;
	bool visited[MAX] = {true,};
	Q.push(0);
	while(!Q.empty()){
		int a = Q.front(); Q.pop();
		if(a > 0 && !visited[MAX-a]){
			visited[MAX-a] = true;
			Q.push(MAX-a);
		}
		for(int i = 0; i < N; ++i){
			int b = (a+A[i]) % MAX;
			if(b < MAX && !visited[b]){
				visited[b] = true;
				Q.push(b);
			}
		}
	}

	for(int i = 0; i < K; ++i){
		int a;
		scanf("%d", &a);
		puts(visited[a] ? "YES" : "NO");
	}
}