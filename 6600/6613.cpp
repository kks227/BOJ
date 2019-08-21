#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
const int MAX = 2000000;
const int MAX_B = 1000;
typedef pair<int, int> P;

int main(){
	int N;
	char B[MAX_B+1];
	while(scanf("%d %s\n", &N, B) > 0){
		int M = strlen(B), p[MAX_B] = {0,};
		for(int i = 1, j = 0; i < M; ++i){
			while(j > 0 && B[i] != B[j]) j = p[j-1];
			if(B[i] == B[j]) p[i] = ++j;
		}

		for(int l = 0; l < N; ++l){
			char A[MAX+1];
			int N = 0;
			while(1){
				A[N] = getchar();
				if(A[N] == '\n'){
					A[N] = '\0';
					break;
				}
				else ++N;
			}

			char C[MAX+1];
			int s[MAX], k = 0;
			for(int i = 0, j = 0; i < N; ++i){
				s[k] = j;
				while(j > 0 && A[i] != B[j]) j = p[j-1];
				C[k++] = A[i];
				if(A[i] == B[j]){
					if(j == M-1){
						j = s[k-M];
						k -= M;
					}
					else j++;
				}
			}
			C[k] = '\0';
			puts(C);
		}
	}
}