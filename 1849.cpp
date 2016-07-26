#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100000; // N의 최댓값
const int ST_MAX = 262144; // 세그먼트트리 배열의 최댓값

// 세그먼트 트리 구조체
struct SegTree{
	int size, start;
	int arr[ST_MAX];
	// 생성자: size=n으로 초기화
	SegTree(int n){
		size = n;
		start = 1;
		while(start < size) start *= 2;
		memset(arr, 0, sizeof(arr));
	}
	// i번 원소를 1 증가시킴
	void inc(int i){
		i += start;
		while(i > 0){
			arr[i]++;
			i /= 2;
		}
	}
	// s 이상 e 미만 인덱스의 원소 합 리턴
	int sum(int s, int e){ return sum(s, e, 1, 0, start); }
	int sum(int s, int e, int node, int ns, int ne){
		if(e <= ns || ne <= s) return 0;
		if(s <= ns && ne <= e) return arr[node];
		int mid = (ns+ne)/2;
		return sum(s, e, node*2, ns, mid) + sum(s, e, node*2+1, mid, ne);
	}
};

int main(){
	// filled: 현재까지 알려진, seq에서 처음 등장하는 안 채워진 인덱스
	int N, seq[100000] = {0}, filled = 0;
	scanf("%d", &N);
	SegTree ST(N);

	// A[i] 입력받기 시작
	for(int i=1; i<=N; i++){
		int A;
		scanf("%d", &A);

		// A=0인 경우 가장 앞쪽의 빈 칸을 찾아 넣음
		if(A == 0){
			while(seq[filled] != 0) filled++;
			seq[filled] = i;
			ST.inc(filled++);
		}
		// A가 0이 아닌 경우
		else{
			// 이진 탐색
			int lo = 0, hi = N;
			while(lo+1 < hi){
				int mid = (lo+hi)/2;
				if(mid - ST.sum(0, mid+1) < A) lo = mid;
				else hi = mid;
			}
			// lo가 불가능한 가장 큰 인덱스, hi가 가능한 가장 작은 인덱스
			seq[lo+1] = i;
			ST.inc(lo+1);
		}
	}

	// 수열 출력
	for(int i=0; i<N; i++)
		printf("%d\n", seq[i]);
}