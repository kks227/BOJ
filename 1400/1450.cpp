#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int N, C, E[2], W[30], sum;
vector<int> val[2];

void dfs(bool side, int pos){
	if(sum > C) return;
	if(pos == E[side]){
		val[side].push_back(sum);
		return;
	}
	dfs(side, pos+1);
	sum += W[pos];
	dfs(side, pos+1);
	sum -= W[pos];
}

int main(){
	scanf("%d %d", &N, &C);
	for(int i=0; i<N; i++)
		scanf("%d", W+i);
	for(int i=0; i<2; i++){
		E[i] = N/(!i+1);
		dfs(i, i?E[0]:0);
		sort(val[i].begin(), val[i].end());
	}

	int result = 0, i = 0, j = val[1].size();
	for(; i<val[0].size(); i++){
		while(j > 0 && val[0][i]+val[1][j-1] > C) j--;
		if(val[0][i]+val[1][0] > C) break;
		result += j;
	}
	printf("%d\n", result);
}