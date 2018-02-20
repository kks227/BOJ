#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int N, cnt[2001] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int L;
		scanf("%d", &L);
		cnt[L]++;
	}
	int result = -1, val = -1;
	for(int i=2; i<=4000; i++){
		int temp = (i%2 ? 0 : cnt[i/2]/2);
		for(int j=max(i-2000, 1); j<min((i+1)/2, 2000); j++)
			temp += min(cnt[j], cnt[i-j]);
		if(temp > result){
			result = temp;
			val = 1;
		}
		else if(temp == result) val++;
	}
	printf("%d %d\n", result, val);
}