#include <cstdio>
#include <algorithm>
using namespace std;

struct Answer{
	long long score;
	int l, r;
	Answer(): Answer(0, 0, 0){}
	Answer(long long s1, int l1, int r1): score(s1), l(l1), r(r1){}
	bool operator <(const Answer &O)const{ return score < O.score; }
	bool operator >(const Answer &O)const{ return score > O.score; }
};

int N, A[100000];

Answer maxScore(int s, int e){
	if(s+1 == e) return Answer(1LL*A[s]*A[s], s, e);

	int mid = (s+e)/2;
	// 양쪽 구간의 최대 점수
	Answer result = max(maxScore(s, mid), maxScore(mid, e));

	// 양쪽 구간에 걸쳐있는 형태 중 최대 점수를 구함
	long long sum = A[mid], minVal = A[mid];
	result = max(result, Answer(sum*minVal, mid, mid+1));
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
		result = max(result, Answer(sum*minVal, lo, hi+1));
	}
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", A+i);
	Answer result = maxScore(0, N);
	printf("%lld\n%d %d\n", result.score, result.l+1, result.r);
}