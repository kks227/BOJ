#include <cstdio>
#include <algorithm>
using namespace std;

int cnt[3], result = 0;

void dfs(int pos, int remain){
	if(remain == 0){
		if(pos == 3 && cnt[0] >= cnt[1]+2 && cnt[2]%2 == 0) result++;
		return;
	}
	if(pos == 3) return;
	for(int i=1; i<=remain; i++){
		cnt[pos] = i;
		dfs(pos+1, remain-i);
	}
}

int main(){
	int N;
	scanf("%d", &N);
	dfs(0, N);
	printf("%d\n", result);
}