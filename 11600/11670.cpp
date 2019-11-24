#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 2500;

long long A[MAX];
vector<long long> adj[MAX];
unordered_map<long long, int> B;
bool visited[MAX];

bool dfs(int a){
	visited[a] = true;
	for(long long b: adj[a]){
		int a2 = (B.find(b) == B.end() ? -1 : B[b]);
		if(a2 == -1 || !visited[a2] && dfs(a2)){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	int N, a[MAX], b[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		scanf("%d %d", a+i, b+i);
		adj[i].push_back(a[i]+b[i]);
		adj[i].push_back(a[i]-b[i]);
		adj[i].push_back(1LL*a[i]*b[i]);
	}
	fill(A, A+N, -1);
	for(int i = 0; i < N; ++i){
		fill(visited, visited+N, false);
		if(!dfs(i)){
			puts("impossible");
			return 0;
		}
	}
	for(int i = 0; i < N; ++i){
		char op;
		if(a[i]+b[i] == A[i]) op = '+';
		else if(a[i]-b[i] == A[i]) op = '-';
		else op = '*';
		printf("%d %c %d = %lld\n", a[i], op, b[i], A[i]);
	}
}