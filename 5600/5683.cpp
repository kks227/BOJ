#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie{
	Trie *go[26];
	bool terminate;
	Trie(): terminate(false){ fill(go, go+26, nullptr); }
	~Trie(){
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	int insert(char *str){
		if(*str == '\0'){
			if(terminate) return false;
			terminate = true;
			return 0;
		}
		else{
			if(!go[*str-'a']) go[*str-'a'] = new Trie;
			go[*str-'a']->insert(str+1);
		}
	}
	int cntNodes(int *cnt, bool isRoot=false){
		int nodes = 1;
		for(int i=0; i<26; i++){
			if(go[i]){
				if(!isRoot) cnt[i]++;
				nodes += go[i]->cntNodes(cnt);
			}
		}
		return nodes;
	}
	long long cntWords(int *cnt, int suffixNodes, bool isRoot=false){
		long long result = 0;
		if(!isRoot) result += suffixNodes;
		for(int i=0; i<26; i++){
			if(go[i]){
				if(!isRoot) result -= cnt[i];
				result += go[i]->cntWords(cnt, suffixNodes);
			}
		}
		return result;
	}
};

int main(){
	while(1){
		int P, S;
		scanf("%d %d", &P, &S);
		if(P == 0) break;

		Trie *prefix = new Trie, *suffix = new Trie;
		for(int i=0; i<P; i++){
			char W[1001];
			scanf("%s", W);
			prefix->insert(W);
		}
		for(int i=0; i<S; i++){
			char W[1001];
			scanf("%s", W);
			reverse(W, W+strlen(W));
			suffix->insert(W);
		}

		int cnt[26] = {0};
		int nodes = suffix->cntNodes(cnt, true) - 1;
		printf("%lld\n", prefix->cntWords(cnt, nodes, true));
		delete prefix;
		delete suffix;
	}
}