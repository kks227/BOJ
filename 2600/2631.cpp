#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, arr[200], cache[200];

int LIS(int pos){
	if(pos == N) return 0;
	int &ret = cache[pos];
	if(ret != -1) return ret;
	ret = 1;
	for(int i=pos+1; i<N; i++)
		if(arr[pos] < arr[i]) ret = max(ret, LIS(i)+1);
	return ret;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d", arr+i);
	memset(cache, -1, sizeof(cache));
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, LIS(i));
	printf("%d\n", N-result);
}