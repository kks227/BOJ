#include <cstdio>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
const int IMPOSSIBLE = 1e9;
typedef pair<int, int> P;

int N, threshold, cost[32], value[32];
map<int, int> H[2];
int currCost, currValue;

void dfs(int pos, bool flag){
	if(pos == (flag ? N : threshold)){
		auto iter = H[flag].find(currValue);
		if(iter == H[flag].end()) H[flag][currValue] = currCost;
		else iter->second = min(currCost, iter->second);
		return;
	}

	dfs(pos+1, flag);
	currCost += cost[pos];
	currValue += value[pos];
	dfs(pos+1, flag);
	currCost -= cost[pos];
	currValue -= value[pos];
}

int main(){
	int K, M, cost0 = 0;
	scanf("%d", &N);
	threshold = N/2;
	for(int i=0; i<N; i++)
		scanf("%d", cost+i);
	for(int i=0; i<N; i++)
		scanf("%d", value+i);
	scanf("%d %d", &K, &M);
	for(int i=0; i<M; i++){
		int temp;
		scanf("%d", &temp);
		cost0 += cost[temp];
	}
	dfs(0, false);
	dfs(threshold, true);

	int result = IMPOSSIBLE;
	auto iter1 = H[0].begin(), iter2 = H[1].end();
	int minRightCost = (--iter2)->second;
	for(; iter1 != H[0].end(); iter1++){
		while(iter1->first + iter2->first >= K){
			result = min(iter1->second + minRightCost, result);
			if(iter2 == H[1].begin()) break;
			else if(iter1->first + (--iter2)->first < K){
				iter2++;
				break;
			}
			else minRightCost = min(iter2->second, minRightCost);
		}
	}

	if(result == IMPOSSIBLE) puts("-1");
	else printf("%d\n", max(result - cost0, 0));
}