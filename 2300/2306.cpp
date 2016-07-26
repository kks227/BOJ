#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char DNA[501];
int N, cache[500][501];

int maxKOI(int start, int end){
	if(start == N) return 0;
	if(start == end) return 0;
	int &ret = cache[start][end];
	if(ret != -1) return ret;
	ret = maxKOI(start+1, end);
	if(DNA[start] == 'a'){
		for(int i=start+1; i<end; i++)
			if(DNA[i] == 't') ret = max(ret, maxKOI(start+1, i) + maxKOI(i+1, end) + 2);
	}
	else if(DNA[start] == 'g'){
		for(int i=start+1; i<end; i++)
			if(DNA[i] == 'c') ret = max(ret, maxKOI(start+1, i) + maxKOI(i+1, end) + 2);
	}
	return ret;
}

int main(){
	scanf("%s", DNA);
	N = strlen(DNA);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", maxKOI(0, N));
}