#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 500;
const int MAX_L = 500;
const int MAX_TRIE = MAX*MAX_L*2+1;

struct TrieNode{
	int go[4];
	bool output[2];
	TrieNode(){
		fill(go, go+4, -1);
		output[0] = output[1] = false;
	}
};

struct Trie{
	TrieNode tNode[MAX_TRIE];
	int size;
	Trie(): size(1){}
	int insert(int curr, int i, int k){
		int &ret = tNode[curr].go[i];
		if(ret < 0) ret = size++;
		tNode[ret].output[k] = true;
		return ret;
	}
};

int main(){
	int N, M;
	char S[2][MAX][MAX_L+1];
	scanf("%d %d", &N, &M);
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < N; ++j)
			scanf("%s", S[i][j]);

	int result = M;
	unordered_map<char, int> C2I;
	C2I['A'] = 0; C2I['C'] = 1; C2I['G'] = 2; C2I['T'] = 3;
	for(int i = 0; i < M; ++i){
		Trie TR;
		int node[2][MAX];
		for(int k = 0; k < 2; ++k)
			fill(node[k], node[k]+N, 0);
		for(int j = i; j < M && j+1-i < result; ++j){
			bool flag = true;
			for(int k = 0; k < 2; ++k){
				for(int l = 0; l < N; ++l){
					node[k][l] = TR.insert(node[k][l], C2I[S[k][l][j]], k);
					if(TR.tNode[node[k][l]].output[0] && TR.tNode[node[k][l]].output[1]) flag = false;
				}
			}
			if(flag){
				result = min(j+1-i, result);
				break;
			}
		}
	}
	printf("%d\n", result);
}