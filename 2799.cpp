#include <cstdio>
using namespace std;

int main(){
	int M, N;
	char S[501][502];
	scanf("%d %d", &M, &N);
	for(int i=0; i<5*M+1; i++)
		scanf("%s", S[i]);
	int cnt[5] = {0};
	for(int i=0; i<M; i++)
		for(int j=0; j<N; j++){
			int temp = 0;
			for(int k=0; k<4; k++)
				if(S[i*5+k+1][j*5+1] == '*') temp++;
			cnt[temp]++;
		}
	for(int i=0; i<5; i++)
		printf("%d ", cnt[i]);
}