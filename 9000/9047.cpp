#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

#define DEST 6174

int cache[10000];

int kaprekar(int n){
	int &ret = cache[n];
	if(ret != -1) return ret;
	if(n == DEST) return ret = 0;

	int temp[4];
	for(int i=0; i<4; i++){
		temp[i] = n%10;
		n /= 10;
	}
	sort(temp, temp+4);
	return ret = kaprekar(temp[3]*1000+temp[2]*100+temp[1]*10+temp[0]-temp[0]*1000-temp[1]*100-temp[2]*10-temp[3]) + 1;
}

int main(){

	int T, N;
	memset(cache, -1, sizeof(int)*10000);
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		printf("%d\n", kaprekar(N));
	}

	return 0;
}