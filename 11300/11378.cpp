#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_N = 1000;

int A[MAX_N], B[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];

bool dfs(int a){
	for(int b: adj[a]){
		if(visited[b]) continue;
		visited[b] = true;
		if(B[b] == -1 || dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for(int i=0; i<N; i++){
		int cnt;
		scanf("%d", &cnt);
		for(int j=0; j<cnt; j++){
			int val;
			scanf("%d", &val);
			adj[i].push_back(val-1);
		}
	}
	fill(A, A+MAX_N, -1);
	fill(B, B+MAX_N, -1);

	// 먼저 각 사원에 대해 가능한 매칭을 시도하고 시작
	int result = 0;
	for(int i=0; i<N; i++){
		fill(visited, visited+MAX_N, false);
		if(dfs(i)) result++;
	}
	// 남은 K개의 매칭을 아무곳에서나 가능할 때까지 채워감
	int over = 0;
	while(1){
		bool success = false;
		for(int i=0; i<N && over<K; i++){
			fill(visited, visited+MAX_N, false);
			if(dfs(i)){
				result++;
				success = true;
				over++;
				break;
			}
		}
		if(!success) break;
	}
	printf("%d\n", result);
}