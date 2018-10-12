#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
	int N, A[MAX], B[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
		scanf("%d", A+i);
	for(int i = 0; i < N; i++)
		scanf("%d", B+i);

	int lo = -1, hi = MAX;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;

		int M = 0, pos[MAX], pcnt = 0, curr = 0, temp[MAX+1] = {0};
		for(int i = 0; i < N; i++)
			if(B[i] > mid) pos[M++] = i;
		fill(pos+M, pos+N, N);

		bool dp[MAX] = {0}, flag = true;
		for(int i = 0; i < N; i++){
			curr += temp[i];
			if(curr > 0) dp[i] = true;
			if(B[i] > mid) pcnt++;

			if(flag){
				if(A[i] == 1) dp[i] = true;
				else{
					int pTemp = pcnt+A[i]-2, p1 = i+A[i]-1, p2 = pos[pTemp]+1;
					if(p1 < N) temp[p1]++;
					if(p2 < N) temp[p2]--;
				}
				if(B[i] > mid) flag = false;
				else dp[i] = true;
			}
			if(dp[i]) flag = true;
		}

		(dp[N-1] ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}