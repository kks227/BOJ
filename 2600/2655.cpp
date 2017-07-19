#include <cstdio>
#include <algorithm>
using namespace std;

struct Block{
	int base, height, weight, n;
	Block(){}
	Block(int b, int h, int w, int n1): base(b), height(h), weight(w), n(n1){}
	bool operator <(const Block& O)const{ return base > O.base; }
};

int N, dp[100], B, bn[100];
Block block[100];

int tower(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=pos+1; i<N; i++)
		if(block[pos].weight > block[i].weight) ret = max(tower(i), ret);
	return ret += block[pos].height;
}

void trace(int pos, int remain){
	bn[B++] = block[pos].n;
	for(int i=pos+1; i<N; i++){
		if(block[pos].weight > block[i].weight && tower(i) == remain){
			trace(i, remain - block[i].height);
			return;
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int b, h, w;
		scanf("%d %d %d", &b, &h, &w);
		block[i] = Block(b, h, w, i+1);
	}
	sort(block, block+N);
	fill(dp, dp+100, -1);

	int result = -1, base = -1;
	for(int i=0; i<N; i++){
		int temp = tower(i);
		if(result < temp){
			result = temp;
			base = i;
		}
	}
	trace(base, result - block[base].height);
	printf("%d\n", B);
	for(int i=B-1; i>=0; i--)
		printf("%d\n", bn[i]);
}