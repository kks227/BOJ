#include <cstdio>
#include <algorithm>
using namespace std;

int N, A[100000];

long long maxScore(int s, int e){
	if(s+1 == e) return 1LL*A[s]*A[s];

	int mid = (s+e)/2;
	// 양쪽 구간의 최대 점수
	long long result = max(maxScore(s, mid), maxScore(mid, e));

	// 양쪽 구간에 걸쳐있는 형태 중 최대 점수를 구함
	long long sum = A[mid], minVal = A[mid];
	result = max(result, sum*minVal);
	for(int lo=mid, hi=mid; lo>s || hi<e-1;){
		// 왼쪽, 오른쪽 중 더 큰 값 쪽으로 확장해나감
		if(lo == s || hi < e-1 && A[lo-1] < A[hi+1]){
			sum += A[++hi];
			minVal = min(minVal, (long long)A[hi]);
		}
		else{
			sum += A[--lo];
			minVal = min(minVal, (long long)A[lo]);
		}
		result = max(result, sum*minVal);
	}
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	printf("%lld\n", maxScore(0, N));
}