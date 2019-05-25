#include <cstdio>
#include <vector>
using namespace std;
const int MAX = 100;
const long long int INF = (1LL<<32);

int A[MAX], B[MAX];
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int a){
	visited[a] = true;
	for(int b: adj[a]){
		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N, C[MAX], D[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", C+i);
	for(int i = 0; i < N; ++i)
		scanf("%d", D+i);
	long long lo = 0, hi = INF;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;
		for(int i = 0; i < N; ++i)
			for(int j = 0; j < N; ++j)
				if((C[i] ^ D[j]) >= mid) adj[i].push_back(j);
		fill(A, A+N, -1);
		fill(B, B+N, -1);
		bool flag = true;
		for(int i = 0; i < N; ++i){
			fill(visited, visited+N, false);
			if(!dfs(i)){
				flag = false;
				break;
			}
		}
		(flag ? lo : hi) = mid;
		for(int i = 0; i < N; ++i)
			adj[i].clear();
	}
	printf("%lld\n", lo);
}