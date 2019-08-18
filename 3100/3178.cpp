#include <cstdio>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX = 100;
const int MAX_N = 10000;
const int MAX_TRIE = MAX*MAX_N + 1;

struct Trie{
	int N, go[MAX_TRIE][26];
	Trie(): N(1){ memset(go, -1, sizeof(go)); }

	void insert(char *s, int curr = 0){
		for(int k = 0; s[k]; ++k){
			int i = s[k]-'A';
			if(go[curr][i] == -1) go[curr][i] = N++;
			curr = go[curr][i];
		}
	}
};

int main(){
	int N, K, result = 0;
	scanf("%d %d", &N, &K);
	char S[2][MAX_N][MAX+1] = {0,};
	for(int i = 0; i < N; ++i){
		getchar();
		for(int j = 0; j < K; ++j)
			S[0][i][j] = getchar();
		for(int j = K-1; j >= 0; --j)
			S[1][i][j] = getchar();
	}
	for(int k = 0; k < 2; ++k){
		Trie T;
		for(int i = 0; i < N; ++i)
			T.insert(S[k][i]);
		result += T.N-1;
	}
	printf("%d\n", result);
}