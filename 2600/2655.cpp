#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

struct Block{
	int base, height, weight;
	vector<int> suc;
	Block(){}
	Block(int b, int h, int w): base(b), height(h), weight(w){}
	bool stackable(Block& other){
		return base > other.base && weight > other.weight;
	}
};

int N, dp[100], track[100];
Block block[100];

int maxStack(int cur){
	int &ret = dp[cur];
	if(ret != -1) return ret;

	ret = 0;
	for(int next: block[cur].suc){
		int temp = maxStack(next);
		if(ret < temp){
			ret = temp;
			track[cur] = next;
		}
	}
	return ++ret;
}

void trace(int cur){
	if(!block[cur].suc.empty()) trace(track[cur]);
	printf("%d\n", cur+1);
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int b, h, w;
		scanf("%d %d %d", &b, &h, &w);
		block[i] = Block(b, h, w);
	}
	memset(dp, -1, sizeof(dp));
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(block[i].base > block[j].base && block[i].weight > block[j].weight)
				block[i].suc.push_back(j);

	int result = -1, base = -1;
	for(int i=0; i<N; i++){
		int temp = maxStack(i);
		if(result < temp){
			result = temp;
			base = i;
		}
	}
	printf("%d\n", result);
	trace(base);
}