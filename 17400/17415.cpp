#include <cstdio>
#include <cassert>
#include <algorithm>
using namespace std;
const int MAX = 500001;

int main(){
	int N, K;
	scanf("%d %d", &N, &K);

	int s[MAX], sPos[MAX], S1 = 0, S2 = 0; // 10^k
	fill(sPos, sPos + MAX, -1);
	for(int i = 1, j = 0; ; i = i*10 % K, ++j){
		if(sPos[i] != -1){
			S2 = j - sPos[i];
			S1 -= S2;
			break;
		}
		sPos[i] = j;
		s[S1++] = i;
	}

	int t[MAX], tPos[MAX], T1 = 0, T2 = 0; // 11...1 (k digits)
	fill(tPos, tPos + MAX, -1);
	for(int i = 1, j = 0; ; i = (i*10+1) % K, ++j){
		if(tPos[i] != -1){
			T2 = j - tPos[i];
			T1 -= T2;
			break;
		}
		tPos[i] = j;
		t[T1++] = i;
	}

	int result = 0;
	for(int i = 0; i < N; ++i){
		int A;
		long long B;
		scanf("%d %lld", &A, &B);
		int sTemp = (B < S1 ? s[B] : s[(B-S1)%S2+S1]);
		--B;
		int tTemp = (B < T1 ? t[B] : t[(B-T1)%T2+T1]);
		result = (1LL*result * sTemp + tTemp*A) % K;
	}
	printf("%d\n", result);
}