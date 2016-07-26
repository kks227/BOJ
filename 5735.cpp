#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Trie{
	Trie* go[96];
	Trie *fail;
	bool terminal;

	Trie(){
		memset(go, 0, sizeof(go));
		terminal = false;
	}
	void insert(const char* key){
		if(*key == '\0'){
			terminal = true;
			return;
		}
		int next = *key - 32;
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(key+1);
	}
};

void constructFailFunctions(Trie* root){
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);

	while(!Q.empty()){
		Trie *current = Q.front();
		Q.pop();
		for(int i=0; i<96; i++){
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
			if(next->fail->terminal) next->terminal = true;
			Q.push(next);
		}
	}
}

int main(){
	while(1){
		int N, M;
		scanf("%d %d", &N, &M);
		if(N == 0) break;

		char str[81];
		Trie* root = new Trie;
		for(int i=0; i<N; i++){
			scanf("%s", str);
			root->insert(str);
		}
		getchar();
		constructFailFunctions(root);

		int result = 0;
		for(int i=0; i<M; i++){
			gets(str);
			Trie* current = root;
			for(int c=0; str[c]; c++){
				int next = str[c] - 32;
				while(current != root && !current->go[next])
					current = current->fail;
				if(current->go[next])
					current = current->go[next];
				if(current->terminal){
					result++;
					current = root;
				}
			}
		}
		printf("%d\n", result);
	}
}