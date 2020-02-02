#include <cstdio>
using namespace std;

inline int getSign(int k){
	return k == 0 ? 0 : (k > 0 ? 1 : -1);
}

int N, sign[10][10], result[10], pSum[11];

bool backtrack(int i){
	if(i > 0){
		pSum[i] = pSum[i-1] + result[i-1];
		for(int j = 0; j < i; ++j)
			if(sign[j][i-1] != getSign(pSum[i]-pSum[j])) return false;
	}
	if(i == N) return true;

	for(int k = 0; k < 21; ++k){
		result[i] = k - 10;
		if(backtrack(i+1)) return true;
	}
	return false;
}

int main(){
	scanf("%d\n", &N);
	for(int i = 0; i < N; ++i){
		for(int j = i; j < N; ++j){
			char c = getchar();
			if(c == '+') sign[i][j] = sign[j][i] = 1;
			else if(c == '-') sign[i][j] = sign[j][i] = -1;
		}
	}
	backtrack(0);
	for(int i = 0; i < N; ++i)
		printf("%d ", result[i]);
}