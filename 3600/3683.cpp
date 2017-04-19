#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int A[500], B[500];
bool visited[500];
vector<int> adj[500];

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
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int C, D, V;
		scanf("%d %d %d", &C, &D, &V);
		int c[500], d[500], w[500];
		for(int i=0; i<V; i++){
			char a, b;
			int x, y;
			scanf("\n%c%d %c%d", &a, &x, &b, &y);
			x--; y--;
			if(a == 'C'){
				c[i] = x;
				d[i] = y;
				w[i] = 0;
			}
			else{
				c[i] = y;
				d[i] = x;
				w[i] = 1;
			}
			for(int j=0; j<i; j++){
				if(w[i] == w[j]) continue;
				if(c[i] == c[j] || d[i] == d[j]){
					if(w[j]) adj[i].push_back(j);
					else adj[j].push_back(i);
				}
			}
		}
		
		int result = 0;
		fill(A, A+V, -1);
		fill(B, B+V, -1);
		for(int i=0; i<V; i++){
			if(!w[i] && A[i] == -1){
				fill(visited, visited+V, false);
				if(dfs(i)) result++;
			}
		}
		printf("%d\n", V-result);
		for(int i=0; i<V; i++)
			adj[i].clear();
	}
}