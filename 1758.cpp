#include <cstdio>
#include <algorithm>
using namespace std;

int main(){

	int N;
	long long result = 0, tip[100000];
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%lld", tip+i);
	sort(tip, tip+N);
	for(int j=N-1; j>=0; j--){
		if(tip[j]-(N-1-j) > 0) result += tip[j]-(N-1-j);
	}
	printf("%lld\n", result);

	return 0;
}