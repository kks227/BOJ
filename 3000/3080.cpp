#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
const int MOD = 1000000007;
struct Trie;
typedef pair<char, Trie*> P;

int fact[28] = {1, 1};

struct Trie{
	vector<P> go;
	int degree;

	Trie(){
		degree = 0;
	}
	void insert(const char* key){
		if(*key == '\0'){
			degree++;
			return;
		}
		for(auto &p: go){
			if(p.first == *key){
				p.second->insert(key+1);
				return;
			}
		}
		go.push_back(P(*key, new Trie));
		degree++;
		go.back().second->insert(key+1);
	}
	int cntPerm(){
		if(degree == 0) return 1;
		int result = fact[degree];
		for(auto &p: go)
			result = 1LL * result * p.second->cntPerm() % MOD;
		return result;
	}
};

int main(){
	int N;
	scanf("%d", &N);
	Trie *root = new Trie;
	for(int i=0; i<N; i++){
		char name[3001];
		scanf("%s", name);
		root->insert(name);
	}

	for(int i=2; i<=27; i++)
		fact[i] = 1LL * fact[i-1] * i % MOD;
	printf("%d\n", root->cntPerm());
	delete root;
}