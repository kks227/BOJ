#include <cstdio>
#include <queue>
#include <vector>
#include <map>
using namespace std;
typedef map<vector<bool>, int> wordMap;

struct Trie{
	Trie *go[2], *fail;
	int terminal;

	Trie(){
		go[0] = go[1] = '\0';
		terminal = -1;
	}
	~Trie(){
		if(go[0]) delete go[0];
		if(go[1]) delete go[1];
	}
	void insert(vector<bool> &word, int pos, int k){
		if(pos == word.size()){
			terminal = k;
			return;
		}
		int next = word[pos];
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(word, pos+1, k);
	}
};

void constructFailFunctions(Trie* root){
	queue<Trie*> Q;
	root->fail = root;
	Q.push(root);

	while(!Q.empty()){
		Trie *current = Q.front();
		Q.pop();
		for(int i=0; i<2; i++){
			Trie *next = current->go[i];
			if(!next) continue;

			if(current == root) next->fail = root;
			else{
				Trie *dest = current->fail;
				while(dest != root && !dest->go[i])
					dest = dest->fail;
				if(dest->go[i])
					dest = dest->go[i];
				next->fail = dest;
			}
			if(next->fail->terminal != -1)
				next->terminal = next->fail->terminal;
			Q.push(next);
		}
	}
}



int main(){
	int H1, W1, H2, W2;
	scanf("%d %d %d %d", &H1, &W1, &H2, &W2);
	vector<vector<bool>> P(H1, vector<bool>(W1));
	for(int i=0; i<H1; i++){
		getchar();
		for(int j=0; j<W1; j++)
			P[i][j] = (getchar() == 'o');
	}
	vector<vector<bool>> M(H2, vector<bool>(W2));
	for(int i=0; i<H2; i++){
		getchar();
		for(int j=0; j<W2; j++)
			M[i][j] = (getchar() == 'o');
	}

	wordMap keys;
	vector<int> knum(H1);
	for(int i=0; i<H1; i++){
		wordMap::iterator finder = keys.find(P[i]);
		if(finder == keys.end()){
			keys[P[i]] = i;
			knum[i] = i;
		}
		else knum[i] = finder->second;
	}

	Trie* root = new Trie;
	for(int i=0; i<H1; i++)
		if(knum[i] == i) root->insert(P[i], 0, i);
	constructFailFunctions(root);

	vector<vector<int>> check(H2, vector<int>(H2, -1));
	for(int i=0; i<H2; i++){
		Trie *current = root;
		for(int j=0; j<W2; j++){
			bool next = M[i][j];
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(current->terminal != -1)
				check[i][j] = current->terminal;
		}
	}

	vector<int> pi(H1, 0);
	int w = 0;
	for(int i=1; i<H1; i++){
		while(w > 0 && knum[i] != knum[w]) w = pi[w-1];
		if(knum[i] == knum[w]) pi[i] = ++w;
	}

	int result = 0;
	for(int j=0; j<W2; j++){
		w = 0;
		for(int i=0; i<H2; i++){
			while(w > 0 && check[i][j] != knum[w]) w = pi[w-1];
			if(check[i][j] == knum[w]){
				if(w == H1-1){
					result++;
					w = pi[w];
				}
				else w++;
			}
		}
	}
	printf("%d\n", result);
}