#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	// m: 가장 큰 일일 지출액
	int N, M, money[100000], m;
	scanf("%d %d", &N, &M);
	for(int i=0; i<N; i++){
		scanf("%d", money+i);
		m = max(m, money[i]);
	}
	// N과 M이 같을 경우 답은 일일 최대 지출
	if(N == M){
		printf("%d\n", m);
		return 0;
	}

	// 이분 탐색
	int lo = m-1, hi = 1000000000;
	while(lo+1 < hi){
		int mid = (lo+hi)/2, sum = 0, cnt = 1;
		if(mid < m) cnt = M+1; // mid가 m보다 작으면 불가능
		else{
			for(int i=0; i<N; i++){
				sum += money[i];
				if(sum > mid){
					cnt++;
					sum = money[i];
				}
			}
		}
		if(cnt <= M) hi = mid;
		else lo = mid;
	}
	printf("%d\n", hi);
}