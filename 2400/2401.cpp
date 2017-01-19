#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

int N, L, I[500], dp[100001];
bool match[100000][500];

int paste(int pos){
	int &ret = dp[pos];
	if(ret != -1) return ret;
	if(pos == L) return ret = 0;

	ret = paste(pos+1);
	for(int i=0; i<N; i++)
		if(match[pos][i]) ret = max(ret, paste(pos+I[i]) + I[i]);
	return ret;
}

int main(){
	char S[100001];
	scanf("%s %d", S, &N);
	L = strlen(S);
	for(int k=0; k<N; k++){
		char W[10001];
		scanf("%s", W);
		I[k] = strlen(W);
		if(I[k] > L) continue;

		int p[100000] = {0}, j = 0;
		for(int i=1; i<I[k]; i++){
			while(j > 0 && W[i] != W[j]) j = p[j-1];
			if(W[i] == W[j]) p[i] = ++j;
		}

		j = 0;
		for(int i=0; i<L; i++){
			while(j > 0 && S[i] != W[j]) j = p[j-1];
			if(S[i] == W[j]){
				if(j == I[k]-1){
					match[i-I[k]+1][k] = true;
					j = p[j];
				}
				else j++;
			}
		}
	}

	fill(dp, dp+100001, -1);
	printf("%d\n", paste(0));
}