#include <cstdio>
#include <algorithm>
using namespace std;

struct Trie{
	Trie *go[2];
	int cnt, end;
	Trie(): cnt(0), end(0){ fill(go, go+2, nullptr); }
	void insert(bool *str, int len){
		cnt++;
		if(len == 0) end++;
		else{
			if(!go[*str]) go[*str] = new Trie;
			go[*str]->insert(str+1, len-1);
		}
	}
	int cntMessage(bool *str, int len){
		int result = end;
		if(len > 0 && go[*str])
			result = end + cntMessage(str+1, len-1);
		else if(len == 0) result = cnt;
		return result;
	}
};

int main(){
	int M, N;
	Trie *root = new Trie;
	scanf("%d %d", &M, &N);
	for(int i=0; i<M; i++){
		int L;
		bool W[10000];
		scanf("%d", &L);
		for(int j=0; j<L; j++)
			scanf("%d", W+j);
		root->insert(W, L);
	}
	for(int i=0; i<N; i++){
		int L;
		bool W[10000];
		scanf("%d", &L);
		for(int j=0; j<L; j++)
			scanf("%d", W+j);
		printf("%d\n", root->cntMessage(W, L));
	}
}