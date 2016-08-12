#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, Am[500], Bm[500];
bool visited[500];
vector<int> A[500], B[500];

bool dfs(int a){
	visited[a] = true;
	for(int b: A[a]){
		if(Bm[b] == -1 || !visited[Bm[b]] && dfs(Bm[b])){
			Am[a] = b;
			Bm[b] = a;
			return true;
		}
	}
	return false;
}

int main(){
	scanf("%d %d", &N, &M);
	for(int i=0; i<M; i++){
		int r, c;
		scanf("%d %d", &r, &c);
		A[r-1].push_back(c-1);
		B[c-1].push_back(r-1);
	}
	fill(Am, Am+N, -1);
	fill(Bm, Bm+N, -1);
	int result = 0;
	for(int i=0; i<N; i++){
		if(Am[i] == -1){
			fill(visited, visited+N, false);
			if(dfs(i)) result++;
		}
	}
	printf("%d\n", result);
}