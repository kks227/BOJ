#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, H, B[100000], T[100000];
	scanf("%d %d", &N, &H);
	for(int i=0; i<N; i++)
		scanf("%d", (i%2?T:B)+(i/2));
	N /= 2;
	sort(B, B+N);
	sort(T, T+N);

	int result = N+1, cnt = 0;
	for(int i=0; i<H; i++){
		int val = B+N-upper_bound(B, B+N, i) + T+N-lower_bound(T, T+N, H-i);
		if(val < result){
			result = val;
			cnt = 1;
		}
		else if(val == result) cnt++;
	}
	printf("%d %d\n", result, cnt);
}