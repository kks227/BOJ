#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, K = 0, S[2] = {0}, s[2][100000];
	scanf("%d", &N);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &s[i][j]);
	for(int i=0; i<N; i++){
		S[0] += s[0][i];
		S[1] += s[1][i];
		if(S[0] == S[1]) K = i+1;
	}
	printf("%d\n", K);
}