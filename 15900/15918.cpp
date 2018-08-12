#include <cstdio>
using namespace std;

int N, result = 0, A[24];
bool used[13];

void dfs(int pos){
	if(pos == 2*N){
		result++;
		return;
	}

	if(A[pos] > 0){
		dfs(pos+1);
		return;
	}
	for(int i=1; i<=N; i++){
		if(!used[i] && A[pos+i+1] == 0){
			used[i] = true;
			A[pos] = A[pos+i+1] = i;
			dfs(pos+1);
			used[i] = false;
			A[pos] = A[pos+i+1] = 0;
		}
	}
}

int main(){
	int x, y;
	scanf("%d %d %d", &N, &x, &y);
	A[x-1] = A[y-1] = y-x-1;
	used[y-x-1] = true;
	dfs(0);
	printf("%d\n", result);
}