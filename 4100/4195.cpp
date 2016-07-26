#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

inline int C2I(char c){
	if(c <= 'Z') return c - 'A';
	return c - 'a' + 26;
}

struct Trie{
	Trie* go[52];
	int output;

	Trie(){
		memset(go, 0, sizeof(go));
		output = -1;
	}
	~Trie(){
		for(int i=0; i<52; i++)
			if(go[i]) delete go[i];
	}
	int query(const char* key, int cnt){
		if(*key == '\0'){
			if(output != -1) return output;
			else return output = cnt;
		}
		int next = C2I(*key);
		if(!go[next]){
			go[next] = new Trie;
		}
		return go[next]->query(key+1, cnt);
	}
};

int uf[200000];

int uf_find(int a){
	if(uf[a] < 0) return a;
	return uf[a] = uf_find(uf[a]);
}

void uf_union(int a, int b){
	a = uf_find(a);
	b = uf_find(b);
	if(a != b){
		uf[a] += uf[b];
		uf[b] = a;
	}
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int F, cnt = 0;
		scanf("%d", &F);
		memset(uf, -1, sizeof(uf));
		Trie *root = new Trie;

		for(int i=0; i<F; i++){
			char A[21], B[21];
			scanf("%s %s", A, B);
			int Apos = root->query(A, cnt);
			cnt = max(cnt, Apos+1);
			int Bpos = root->query(B, cnt);
			cnt = max(cnt, Bpos+1);
			uf_union(Apos, Bpos);
			printf("%d\n", -uf[uf_find(Apos)]);
		}
	}
}