#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 300;

int main(){
	int N, A[2][MAX], result = 0, cnt[2] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < N; ++j){
			scanf("%d", &A[i][j]);
			--A[i][j];
		}
	}
	bool turn = 0;
	for(int i = 0; i < N; ++i){
		if(A[0][i] == A[1][i]){
			++cnt[turn];
			cnt[!turn] = 0;
			turn = !turn;
		}
		else if((A[0][i]+1)%3 == A[1][i]){
			++cnt[1];
			cnt[0] = 0;
			turn = 0;
		}
		else{
			++cnt[0];
			cnt[1] = 0;
			turn = 1;
		}
		result = max(max(cnt[0], cnt[1]), result);
	}
	printf("%d\n", result);
}