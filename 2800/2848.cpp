#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(){
	int N, in[26] = {0};
	vector<int> out[26];
	char W[100][11];
	bool exist[26] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		scanf("%s", W[i]);
		for(int j=0; W[i][j]; j++)
			exist[W[i][j]-'a'] = true;
	}

	for(int i=0; i<N-1; i++){
		for(int j=0; W[i][j] && W[i+1][j]; j++){
			if(W[i][j] != W[i+1][j]){
				out[W[i][j]-'a'].push_back(W[i+1][j]-'a');
				in[W[i+1][j]-'a']++;
				break;
			}
			if(W[i][j+1] && !W[i+1][j+1]){
				puts("!");
				return 0;
			}
		}
	}

	int L = 0;
	queue<int> Q;
	for(int i=0; i<26; i++){
		if(exist[i]){
			L++;
			if(in[i] == 0) Q.push(i);
		}
	}
	char result[27] = {0};
	bool multiple = false;
	for(int i=0; i<L; i++){
		if(Q.empty()){
			puts("!");
			return 0;
		}
		if(Q.size() > 1) multiple = true;

		int curr = Q.front();
		Q.pop();
		result[i] = curr+'a';
		for(int next: out[curr])
			if(--in[next] == 0) Q.push(next);
	}
	puts(multiple ? "?" : result);
}