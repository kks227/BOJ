#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 10000;

int main(){
	int N, K, D, A[MAX], B[MAX], C[MAX];
	scanf("%d %d %d", &N, &K, &D);
	for(int i=0; i<K; i++)
		scanf("%d %d %d", A+i, B+i, C+i);
	int lo = 0, hi = N;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		long long sum = 0;
		for(int i=0; i<K; i++){
			int temp = min(mid, B[i]);
			if(temp >= A[i]) sum += (temp-A[i]) / C[i] + 1;
		}
		(sum >= D ? hi : lo) = mid;
	}
	printf("%d\n", hi);
}