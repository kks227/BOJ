#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;
typedef tuple<int, int, char> Triplet;

struct Trie{
	Trie *go[26];
	Trie *fail;
	vector<int> keys;

	Trie(){
		memset(go, 0, sizeof(go));
	}
	~Trie(){
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	void insert(const char* word, int knum){
		if(*word == '\0'){
			keys.push_back(knum);
			return;
		}
		int next = *word - 'A';
		if(!go[next]){
			go[next] = new Trie;
		}
		go[next]->insert(word+1, knum);
	}
};

void constructFailFunctions(Trie* root){
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
				if(dest->go[i])
					dest = dest->go[i];
				next->fail = dest;
			}
			if(!next->fail->keys.empty())
				next->keys.insert(next->keys.begin(), next->fail->keys.begin(), next->fail->keys.end());
			Q.push(next);
		}
	}
}

int main(){
	int R, C, W, len[1000];
	scanf("%d %d %d", &R, &C, &W);
	char P[1000][1001];
	for(int i=0; i<R; i++)
		scanf("%s", P[i]);

	Trie* root = new Trie;
	char word[1001];
	for(int i=0; i<W; i++){
		scanf("%s", word);
		root->insert(word, i);
		len[i] = strlen(word);
	}
	constructFailFunctions(root);

	Triplet ans[1000];
	fill(ans, ans+W, Triplet(-1, -1, '\0'));

	// C: to right
	for(int i=0; i<R; i++){
		Trie* current = root;
		for(int j=0; j<C; j++){
			int next = P[i][j] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i, j-len[w]+1, 'C');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// G: to left
	for(int i=0; i<R; i++){
		Trie* current = root;
		for(int j=C-1; j>=0; j--){
			int next = P[i][j] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i, j+len[w]-1, 'G');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// E: to down
	for(int j=0; j<C; j++){
		Trie* current = root;
		for(int i=0; i<R; i++){
			int next = P[i][j] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i-len[w]+1, j, 'E');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// A: to up
	for(int j=0; j<C; j++){
		Trie* current = root;
		for(int i=R-1; i>=0; i--){
			int next = P[i][j] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i+len[w]-1, j, 'A');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// D: to right down
	for(int i=R-1, j=0; j<C; i>0 ? i-- : j++){
		Trie* current = root;
		for(int k=0; i+k<R && j+k<C; k++){
			int next = P[i+k][j+k] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i+k-len[w]+1, j+k-len[w]+1, 'D');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// F: to left down
	for(int i=R-1, j=C-1; j>=0; i>0 ? i-- : j--){
		Trie* current = root;
		for(int k=0; i+k<R && j-k>=0; k++){
			int next = P[i+k][j-k] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i+k-len[w]+1, j-k+len[w]-1, 'F');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// H: to left up
	for(int i=0, j=C-1; j>=0; i<R-1 ? i++ : j--){
		Trie* current = root;
		for(int k=0; i-k>=0 && j-k>=0; k++){
			int next = P[i-k][j-k] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i-k+len[w]-1, j-k+len[w]-1, 'H');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	// B: to right up
	for(int i=0, j=0; j<C; i<R-1 ? i++ : j++){
		Trie* current = root;
		for(int k=0; i-k>=0 && j+k<C; k++){
			int next = P[i-k][j+k] - 'A';
			while(current != root && !current->go[next])
				current = current->fail;
			if(current->go[next])
				current = current->go[next];
			if(!current->keys.empty())
				for(int w: current->keys){
					Triplet newAns(i-k+len[w]-1, j+k-len[w]+1, 'B');
					if(get<2>(ans[w]) == '\0') ans[w] = newAns;
					else ans[w] = min(ans[w], newAns);
				}
		}
	}

	for(int i=0; i<W; i++)
		printf("%d %d %c\n", get<0>(ans[i]), get<1>(ans[i]), get<2>(ans[i]));
}