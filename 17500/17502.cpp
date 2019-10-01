#include <cstdio>
using namespace std;
const int MAX = 100;

int main(){
	int N;
	char S[MAX+1];
	scanf("%d %s", &N, S);
	for(int i = 0; i < (N+1)/2; ++i){
		int j = N-i-1;
		if(S[i] == '?' && S[j] == '?') S[i] = S[j] = 'a';
		else if(S[i] == '?') S[i] = S[j];
		else if(S[j] == '?') S[j] = S[i];
	}
	puts(S);
}