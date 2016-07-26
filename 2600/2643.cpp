#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, width[100], height[100];
int cache[100];

int maxCnt(int start){
	int &ret = cache[start];
	if(ret != -1) return ret;
	ret = 0;
	for(int i=0; i<N; i++){
		if(i == start) continue;
		if(width[i] <= width[start] && height[i] <= height[start]) ret = max(ret, maxCnt(i));
		if(width[i] <= height[start] && height[i] <= width[start]) ret = max(ret, maxCnt(i));
	}
	return ++ret;
}

int main(){

	memset(cache, -1, sizeof(int)*100);
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", width+i, height+i);
	int result = 0;
	for(int i=0; i<N; i++)
		result = max(result, maxCnt(i));
	printf("%d\n", result);

	return 0;
}