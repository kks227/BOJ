#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, M, A[5000];
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);

	int lo = -1, hi = 10000;
	while(lo+1 < hi){
		int mid = (lo+hi)/2, minVal = A[0], maxVal = A[0];
		bool success = true;
		for(int i=0, j=M; i<N && j>0; i++){
			minVal = min(minVal, A[i]);
			maxVal = max(maxVal, A[i]);
			if(maxVal-minVal > mid){
				if(--j == 0){
					success = false;
					break;
				}
				minVal = maxVal = A[i];
			}
		}
		(success ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}