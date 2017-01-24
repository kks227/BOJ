#include <cstdio>
#include <algorithm>
using namespace std;

struct Trie{
	Trie *go[26];
	bool terminate;
	int branch, words;
	Trie(): terminate(false), branch(0), words(0){ fill(go, go+26, nullptr); }
	~Trie(){
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	void insert(char *str){
		if(*str == '\0'){
			branch++;
			terminate = true;
		}
		else{
			if(!go[*str-'a']){
				branch++;
				go[*str-'a'] = new Trie;
			}
			words++;
			go[*str-'a']->insert(str+1);
		}
	}
	long long cntKeystrokes(bool isRoot=false){
		long long result = 0;
		if(isRoot || branch > 1) result = words;
		for(int i=0; i<26; i++)
			if(go[i]) result += go[i]->cntKeystrokes();
		return result;
	}
};

int main(){
	int N;
	while(scanf("%d", &N) > 0){
		Trie *root = new Trie;
		for(int i=0; i<N; i++){
			char W[81];
			scanf("%s", W);
			root->insert(W);
		}
		printf("%.2lf\n", 1.0*root->cntKeystrokes(true)/N);
		delete root;
	}
}