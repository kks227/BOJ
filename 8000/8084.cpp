#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Trie{
	Trie* go[26];
	int output;
	Trie(){
		fill(go, go+26, nullptr);
		output = 0;
	}
	~Trie(){
		for(int i=0; i<26; i++)
			if(go[i]) delete go[i];
	}
	void insert(char* s, int pos = 0){
		if(!s[pos]){
			output++;
			return;
		}
		int next = s[pos] - 'a';
		if(!go[next]) go[next] = new Trie();
		go[next]->insert(s, pos+1);
	}
	int find(char* s, int pos = 0){
		if(!s[pos]){
			char B[401] = {0};
			return cntPalindrome(B);
		}
		int next = s[pos] - 'a', result = 0;
		if(output > 0){
			bool isP = true;
			int len = strlen(s);
			for(int i=0; i<(len-pos)/2; i++)
				if(s[pos+i] != s[len-i-1]) isP = false;
			result += (isP ? output : 0);
		}
		if(go[next]) result += go[next]->find(s, pos+1);
		return result;
	}
	int cntPalindrome(char* buffer, int bpos = 0){
		int result = 0;
		for(int i=0; i<26; i++){
			if(go[i]){
				buffer[bpos] = 'a'+i;
				result += go[i]->cntPalindrome(buffer, bpos+1);
			}
		}
		if(output > 0){
			bool isP = true;
			for(int i=0; i<bpos/2; i++)
				if(buffer[i] != buffer[bpos-i-1]) isP = false;
			if(isP) result += output;
		}
		return result;
	}
};

int N, threshold, result, L[30][2];
char S[30][2][401], B[401];
Trie* root = new Trie();

void dfs1(int pos, int bpos = 0){
	if(pos == threshold){
		root->insert(B);
		return;
	}
	for(int i=0; i<L[pos][0]; i++) B[bpos+i] = S[pos][0][i];
	dfs1(pos+1, bpos+L[pos][0]);
	for(int i=0; i<L[pos][0]; i++) B[bpos+i] = '\0';
	for(int i=0; i<L[pos][1]; i++) B[bpos+i] = S[pos][1][i];
	dfs1(pos+1, bpos+L[pos][1]);
	for(int i=0; i<L[pos][1]; i++) B[bpos+i] = '\0';
}

void dfs2(int pos, int bpos = 0){
	if(pos == threshold-1){
		result += root->find(B);
		return;
	}
	for(int i=0; i<L[pos][0]; i++) B[bpos+i] = S[pos][0][ L[pos][0]-i-1 ];
	dfs2(pos-1, bpos+L[pos][0]);
	for(int i=0; i<L[pos][0]; i++) B[bpos+i] = '\0';
	for(int i=0; i<L[pos][1]; i++) B[bpos+i] = S[pos][1][ L[pos][1]-i-1 ];
	dfs2(pos-1, bpos+L[pos][1]);
	for(int i=0; i<L[pos][1]; i++) B[bpos+i] = '\0';
}



int main(){
	scanf("%d", &N);
	for(int i=0; i<2; i++){
		for(int j=0; j<N; j++){
			scanf("%s", S[j][i]);
			L[j][i] = strlen(S[j][i]);
		}
	}
	threshold = N/2;
	dfs1(0);
	dfs2(N-1);
	printf("%d\n", result);
}