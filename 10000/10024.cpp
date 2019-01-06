#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100;

int N, A[MAX], B[MAX], go[MAX], res1, res2 = -1, temp;
bool visited[MAX];

void dfs(int curr){
	visited[curr] = true;
	++temp;
	if(!visited[go[curr]]) dfs(go[curr]);
}

int main(){
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", A+i);
	for(int i = 0; i < N; ++i)
		scanf("%d", B+i);
	for(int i = 0; i < N; ++i)
		for(int j = 0; j < N; ++j)
			if(A[i] == B[j]) go[i] = j;

	for(int i = 0; i < N; ++i){
		if(!visited[i] && go[i] != i){
			temp = 0;
			dfs(i);
			++res1;
			res2 = max(temp, res2);
		}
	}
	printf("%d %d\n", res1, res2);
}