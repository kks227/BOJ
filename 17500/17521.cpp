#include <cstdio>
using namespace std;
const int MAX = 15;

int main(){
	int N, s[MAX];
	long long W;
	scanf("%d %lld", &N, &W);
	for(int i = 0; i < N; ++i)
		scanf("%d", s+i);
	for(int i = 0; i < N; ++i){
		int j = i;
		for(; j < N-1 && s[j] >= s[j+1]; ++j);
		int k = j+1;
		for(; k < N-1 && s[k] <= s[k+1]; ++k);
		if(k == N) break;
		long long cnt = W/s[j];
		W += cnt*(s[k]-s[j]);
		i = k;
	}
	printf("%lld\n", W);
}