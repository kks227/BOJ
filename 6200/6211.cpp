#include <cstdio>
#include <algorithm>
using namespace std;

int C, B, val[21], sum, result;

void dfs(int pos){
	if(pos == B){
		result = max(result, sum);
		return;
	}
	dfs(pos+1);
	if(sum+val[pos] <= C){
		sum += val[pos];
		dfs(pos+1);
		sum -= val[pos];
	}
}

int main(){
	scanf("%d %d", &C, &B);
	for(int i=0; i<B; i++)
		scanf("%d", val+i);
	dfs(0);
	printf("%d\n", result);
}