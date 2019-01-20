#include <cstdio>
using namespace std;
const int MAX = 1000000;

int main(){
	int N, A[MAX], B[MAX], cnt[2] = {0,};
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int val;
		scanf("%d", &val);
		A[val-1] = i;
	}
	for(int i = 0; i < N; ++i){
		scanf("%d", B+i);
		B[i] = A[B[i]-1];
		if(i > 0){
			if(B[i]-B[i-1] == 1) ++cnt[0];
			if(B[i]-B[i-1] == -1) ++cnt[1];
		}
	}
	puts(cnt[0] >= N-2 || cnt[1] >= N-2 ? "good puzzle" : "bad puzzle");
}