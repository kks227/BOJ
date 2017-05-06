#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

struct Trie{
	Trie *go[4], *fail;
	int output;
	Trie(){
		fill(go, go+4, nullptr);
		output = 0;
	}
	~Trie(){
		for(int i=0; i<4; i++)
			if(go[i]) delete go[i];
	}
	void insert(const char* key){
		if(*key == '\0'){
			output = 1;
			return;
		}
		int next = *key - '0';
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(key+1);
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M;
		char S[1000001] = {0}, W[101] = {0};
		Trie* root = new Trie;
		scanf("%d %d", &N, &M);
		getchar();
		for(int i=0; i<N; i++){
			switch(getchar()){
				case 'A': S[i] = '0'; break;
				case 'C': S[i] = '1'; break;
				case 'G': S[i] = '2'; break;
				default : S[i] = '3';
			}
		}
		getchar();
		for(int i=0; i<M; i++){
			switch(getchar()){
				case 'A': W[i] = '0'; break;
				case 'C': W[i] = '1'; break;
				case 'G': W[i] = '2'; break;
				default : W[i] = '3';
			}
		}
		root->insert(W);
		for(int i=0; i<=M-2; i++){
			for(int j=i+2; j<=M; j++){
				reverse(W+i, W+j);
				root->insert(W);
				reverse(W+i, W+j);
			}
		}

		queue<Trie*> Q;
		root->fail = root;
		Q.push(root);
		while(!Q.empty()){
			Trie *current = Q.front();
			Q.pop();

			for(int i=0; i<4; i++){
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
				next->output += next->fail->output;

				Q.push(next);
			}
		}

		Trie* current = root;
		int result = 0;
		for(int c=0; S[c]; c++){
			int next = S[c] - '0';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			result += current->output;
		}
		printf("%d\n", result);
		delete root;
	}
}