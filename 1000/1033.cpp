#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[10];
long long result[10];
bool visited[10];

void dfs(int curr, int prev, int c){
	visited[curr] = true;
	result[curr] *= c;
	for(int next: adj[curr])
		if(next != prev && !visited[next]) dfs(next, curr, c);
}

long long gcd(long long p, long long q){
	while(q){
		long long r = p%q;
		p = q;
		q = r;
	}
	return p;
}

int main(){
	int N, a[9], b[9], p[9], q[9];
	scanf("%d", &N);
	for(int i=0; i<N-1; i++){
		scanf("%d %d %d %d", a+i, b+i, p+i, q+i);
		adj[a[i]].push_back(b[i]);
		adj[b[i]].push_back(a[i]);
	}
	fill(result, result+N, 1);
	for(int i=0; i<N-1; i++){
		fill(visited, visited+N, false);
		dfs(a[i], b[i], p[i]);
		dfs(b[i], a[i], q[i]);
	}
	long long g = result[0];
	for(int i=1; i<N; i++)
		g = gcd(g, result[i]);
	for(int i=0; i<N; i++)
		printf("%lld ", result[i]/g);
}