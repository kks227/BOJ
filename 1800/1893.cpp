#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		char A[62], W[50001], S[500001];
		scanf("%s %s %s", A, W, S);
		int K = strlen(A), M = strlen(W), N = strlen(S);

		char C[128];
		for(int i=0; i<K; i++) C[A[i]] = i;
		for(int i=0; i<N; i++) S[i] = C[S[i]];
		for(int i=0; i<M; i++) W[i] = C[W[i]];

		vector<int> result;
		for(int k=0; k<K; k++){
			int pi[50000] = {0}, j = 0;
			for(int i=1; i<M; i++){
				while(j > 0 && W[i] != W[j]) j = pi[j-1];
				if(W[i] == W[j]) pi[i] = ++j;
			}

			int cnt = 0;
			j = 0;
			for(int i=0; i<N; i++){
				while(j > 0 && S[i] != W[j]) j = pi[j-1];
				if(S[i] == W[j]){
					if(j == M-1){
						cnt++;
						j = pi[j];
					}
					else j++;
				}
			}

			if(cnt == 1) result.push_back(k);
			char W2[50001];
			for(int i=0; i<M; i++)
				W2[i] = (W[i]+1) % K;
			memcpy(W, W2, sizeof(W));
		}

		switch(result.size()){
		case 0:
			puts("no solution");
			break;
		case 1:
			printf("unique: %d\n", result[0]);
			break;
		default:
			printf("ambiguous:");
			for(int i: result)
				printf(" %d", i);
			puts("");
		}
	}
}