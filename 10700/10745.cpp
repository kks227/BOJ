#include <cstdio>
#include <cstring>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 100000;

struct Trie{
	Trie *go[26], *fail;
	int output;
	Trie(){
		fill(go, go+26, nullptr);
		output = 0;
	}
	~Trie(){
		for(int i = 0; i < 26; ++i)
			if(go[i]) delete go[i];
	}
	void insert(int len, const char* s){
		if(*s == '\0'){
			output = len;
			return;
		}
		int next = *s - 'a';
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(len, s+1);
	}
};

int main(){
	char A[MAX+1], B[MAX+1];
	int N, M;
	Trie* root = new Trie;
	scanf("%s %d", A, &M);
	N = strlen(A);
	for(int i = 0; i < M; ++i){
		scanf("%s", B);
		root->insert(strlen(B), B);
	}

	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while(!Q.empty()){
		Trie *current = Q.front();
		Q.pop();
		for(int i = 0; i < 26; ++i){
			Trie *next = current->go[i];
			if(!next) continue;

			if(current == root) next->fail = root;
			else{
				Trie *dest = current->fail;
				while(dest != root && !dest->go[i])
					dest = dest->fail;
				if(dest->go[i]) dest = dest->go[i];
				next->fail = dest;
			}
			Q.push(next);
		}
	}

	char C[MAX+1];
	int k = 0;
	Trie *current = root, *s[MAX] = {nullptr,};
	unordered_map <Trie*, Trie*> dp[26];
	for(int i = 0; i < N; ++i){
		int next = A[i] - 'a';
		s[k] = current;
		if(current != root && !current->go[next]){
			if(dp[next].find(current) != dp[next].end())
				current = dp[next][current];
			else{
				Trie *previous = current;
				while(current != root && !current->go[next])
					current = current->fail;
				dp[next][previous] = current;
			}
		}
		C[k++] = A[i];
		if(current->go[next])
			current = current->go[next];
		int temp = current->output;
		if(temp > 0){
			current = s[k - temp];
			k -= temp;
		}
	}
	C[k] = '\0';
	puts(C);

	delete root;
}