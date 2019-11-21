#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 100000;

int main(){
	int N, c[MAX], rMax[MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i)
		scanf("%d", c+i);
	rMax[N-1] = c[N-1];
	for(int i = N-2; i >= 0; --i)
		rMax[i] = max(rMax[i+1], c[i]);
	long long result = 0, sum = 0;
	int cnt = 0;
	for(int i = 0; i < N; ++i){
		if(c[i] == rMax[i]){
			result += cnt*c[i] - sum;
			sum = cnt = 0;
		}
		else{
			sum += c[i];
			++cnt;
		}
	}
	printf("%lld\n", result);
}