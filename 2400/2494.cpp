#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A[10000], B[10000], dp[10000][10];

int digits(int pos, int offset){
	if(pos == N) return 0;
	int &ret = dp[pos][offset];
	if(ret != -1) return ret;

	int actual = (A[pos] + offset) % 10;
	ret = 1000000000;
	for(int i=0; i<10; i++){
		if((actual+i)%10 == B[pos]){
			ret = min(ret, digits(pos+1, (offset+i)%10) + i);
			ret = min(ret, digits(pos+1, offset) + 10-i);
			break;
		}
	}
	return ret;
}

void track(int pos, int offset){
	if(pos == N) return;

	int actual = (A[pos] + offset) % 10;
	for(int i=0; i<10; i++){
		if((actual+i)%10 == B[pos]){
			int left = digits(pos+1, (offset+i)%10) + i;
			int right = digits(pos+1, offset) + 10-i;
			if(left <= right){
				printf("%d %d\n", pos+1, i);
				track(pos+1, (offset+i)%10);
			}
			else{
				printf("%d %d\n", pos+1, i-10);
				track(pos+1, offset);
			}
			return;
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%1d", A+i);
	for(int i=0; i<N; i++)
		scanf("%1d", B+i);
	memset(dp, -1, sizeof(dp));
	printf("%d\n", digits(0, 0));
	track(0, 0);
}