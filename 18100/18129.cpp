#include <cstdio>
using namespace std;
const int MAX = 2000;

int main(){
	char S[MAX+1];
	int K;
	bool used[26] = {false,};
	scanf("%s %d", S, &K);
	for(int i = 0; S[i]; ){
		if(S[i] < 'a') S[i] += 'a'-'A';
		int j;
		for(j = i+1; S[j] && (S[i] == S[j] || S[i] == S[j] + 'a'-'A'); ++j);
		if(!used[S[i]-'a']){
			used[S[i]-'a'] = true;
			putchar(j-i >= K ? '1' : '0');
		}
		i = j;
	}
}