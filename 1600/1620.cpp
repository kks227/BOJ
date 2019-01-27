#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int MAX_L = 21;

struct Trie{
	int go[26], output;
	Trie();
	void insert(char *s, int val);
	void find(char *s);
};

int tcnt;
Trie node[MAX*MAX_L];

int main(){
	int N, M;
	char S[MAX][MAX_L];
	Trie& root = node[tcnt++];
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; ++i){
		scanf("%s", S[i]);
		S[i][0] += ('a'-'A');
		root.insert(S[i], i);
		S[i][0] -= ('a'-'A');
	}
	for(int i = 0; i < M; ++i){
		char q[MAX_L];
		scanf("%s", q);
		if(q[0] <= '9'){
			int k;
			sscanf(q, "%d", &k);
			puts(S[k]);
		}
		else{
			q[0] += ('a'-'A');
			root.find(q);
		}
	}
}



Trie::Trie(){
	fill(go, go+26, -1);
	output = -1;
}

void Trie::insert(char *s, int val){
	if(*s == '\0'){
		output = val;
		return;
	}
	int k = *s - 'a';
	if(go[k] < 0) go[k] = tcnt++;
	node[go[k]].insert(s+1, val);
}

void Trie::find(char *s){
	if(*s == '\0'){
		printf("%d\n", output);
		return;
	}
	int k = *s - 'a';
	node[go[k]].find(s+1);
}