#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Trie{
	Trie* go[26];
	Trie *fail;
	bool output;
	Trie(){
		fill(go, go+26, nullptr);
		output = false;
	}
	~Trie(){
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	void insert(const char* key){
		if(*key == '\0'){
			output = true;
			return;
		}
		int next = *key - 'a';
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(key+1);
	}
};

int main(){
	int N, M;
	char str[10001];
	Trie* root = new Trie;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", str);
		root->insert(str);
	}

	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);
	while(!Q.empty()){
		Trie *current = Q.front();
		Q.pop();
		for(int i=0; i<26; i++){
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
			if(next->fail->output) next->output = true;
			Q.push(next);
		}
	}

	scanf("%d", &M);
	for(int i=0; i<M; i++){
		scanf("%s", str);
		Trie* current = root;
		bool result = false;
		for(int c=0; str[c]; c++){
			int next = str[c] - 'a';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(current->output){
				result = true;
				break;
			}
		}
		puts(result ? "YES" : "NO");
	}
	delete root;
}