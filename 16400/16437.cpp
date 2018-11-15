#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 123456;

int N, a[MAX], p[MAX];
bool flag[MAX];
vector<int> adj[MAX];

long long dfs(int curr){
	long long temp = 0;
	for(int next: adj[curr])
		temp += dfs(next);
	if(flag[curr]) return max(temp - a[curr], 0LL);
	return temp += a[curr];
}

int main(){
	scanf("%d", &N);
	for(int i = 1; i < N; ++i){
		char c;
		scanf(" %c %d %d", &c, a+i, p+i);
		flag[i] = (c == 'W');
		adj[--p[i]].push_back(i);
	}
	printf("%lld\n", dfs(0));
}