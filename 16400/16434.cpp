#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 123456;

int main(){
	int N, ha, t[MAX], a[MAX], h[MAX];
	scanf("%d %d", &N, &ha);
	for(int i = 0; i < N; ++i)
		scanf("%d %d %d", t+i, a+i, h+i);
	long long lo = 0, hi = 1e18;
	while(lo+1 < hi){
		long long mid = (lo+hi)/2;

		long long currAtk = ha, currHp = mid;
		bool flag = true;
		for(int i = 0; i < N; ++i){
			if(t[i] == 1){
				if((h[i]-1)/currAtk > (currHp-1)/a[i]){
					flag = false;
					break;
				}
				currHp -= (h[i]-1)/currAtk*a[i];
			}
			else{
				currAtk += a[i];
				currHp = min(currHp+h[i], mid);
			}
		}
		(flag ? hi : lo) = mid;
	}
	printf("%lld\n", hi);
}