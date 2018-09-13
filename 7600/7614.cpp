#include <cstdio>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int N, M, K, pivot;
unsigned long long S[50], B;
vector<int> result;
unordered_map<unsigned long long, int> H[11];

int pos, cnt;
unsigned long long val;
unsigned int chosen;

void dfs1(){
	if(pos == pivot){
		H[cnt][val] = chosen;
		return;
	}

	pos++;
	dfs1();
	if(cnt < K){
		cnt++; chosen += 1<<pos-1; val ^= S[pos-1];
		dfs1();
		cnt--; chosen -= 1<<pos-1; val ^= S[pos-1];
	}
	pos--;
}

bool dfs2(){
	if(pos == M){
		for(int i=0; i<=K-cnt; i++){
			if(H[i].find(val ^ B) != H[i].end()){
				unsigned int temp = H[i][val ^ B];
				for(int j=0; j<pivot; j++)
					if(temp & 1<<j) result.push_back(j);
				return true;
			}
		}
		return false;
	}

	pos++;
	if(dfs2()){
		pos--;
		return true;
	}
	if(cnt < K){
		cnt++; val ^= S[pos-1];
		if(dfs2()){
			result.push_back(--pos);
			return true;
		}
		cnt--; val ^= S[pos-1];
	}
	pos--;
	return false;
}

int main(){
	scanf("%d %d\n", &N, &K);
	while(1){
		char c = getchar();
		if(c == ' ') break;
		S[M++] = c-'0';
	}
	scanf("%1llu", &B);
	for(int i=1; i<N; i++){
		unsigned long long val;
		for(int j=0; j<M; j++){
			scanf("%1llu", &val);
			S[j] += val << i;
		}
		scanf("%1llu", &val);
		B += val << i;
	}

	pivot = min(20, M-1);
	dfs1();
	pos = pivot;
	if(dfs2()){
		printf("%d\n", result.size());
		for(int val: result)
			printf("%d\n", val);
	}
	else puts("-1");
}