#include <cstdio>
#include <cstring>
#include <vector>
#include <utility>
using namespace std;
const int MAX = 1000000;
const int MAX_B = 36;
typedef pair<int, int> P;

int main(){
	char A[MAX+1], B[MAX_B+1];
	scanf("%s %s", A, B);
	int N = strlen(A), M = strlen(B), p[MAX_B] = {0};
	for(int i = 1, j = 0; i < M; ++i){
		while(j > 0 && B[i] != B[j]) j = p[j-1];
		if(B[i] == B[j]) p[i] = ++j;
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
	puts(k>0 ? C : "FRULA");
}