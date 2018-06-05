#include <cstdio>
using namespace std;

int main(){
	int N, M;
	bool adj[26][26] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		char u, v;
		scanf(" %c is %c", &u, &v);
		adj[u-'a'][v-'a'] = true;
	}
	for(int k=0; k<26; k++)
		for(int i=0; i<26; i++)
			for(int j=0; j<26; j++)
				if(adj[i][k] && adj[k][j]) adj[i][j] = true;
	scanf("%d", &M);
	for(int i=0; i<M; i++){
		char u, v;
		scanf(" %c is %c", &u, &v);
		puts(adj[u-'a'][v-'a'] ? "T" : "F");
	}
}