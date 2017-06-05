#include <cstdio>
using namespace std;

int A, B, result;

void dfs(long long n){
	if(n > B) return;
	if(n >= A) result++;
	dfs(n*10+4);
	dfs(n*10+7);
}

int main(){
	scanf("%d %d", &A, &B);
	dfs(0);
	printf("%d\n", result);
}