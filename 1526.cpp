#include <cstdio>
#include <algorithm>
using namespace std;

int result = 4, N;

void DFS(int n){
	if(n > N) return;
	result = max(result, n);
	DFS(n*10+4);
	DFS(n*10+7);
}

int main(){
	scanf("%d", &N);
	DFS(0);
	printf("%d\n", result);
}