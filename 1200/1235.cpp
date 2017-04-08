#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;

int cnt;

struct Trie{
	int tn;
	Trie* go[10];
	Trie(){
		tn = cnt++;
		fill(go, go+10, nullptr);
	}
	Trie* insert(int d){
		if(!go[d]) go[d] = new Trie;
		return go[d];
	}
};

int main(){
	int N;
	char id[1000][101];
	scanf("%d", &N);
	Trie* root = new Trie;
	Trie* node[1000];
	for(int i=0; i<N; i++){
		scanf("%s", id[i]);
		node[i] = root;
	}
	int L = strlen(id[0]);

	for(int k=1; ; k++){
		set<int> S;
		for(int i=0; i<N; i++){
			node[i] = node[i]->insert(id[i][L-k]-'0');
			S.insert(node[i]->tn);
		}
		if(S.size() == N){
			printf("%d\n", k);
			break;
		}
	}
}