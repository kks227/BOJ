#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char S[1001];
int cache[2501][2501];
bool isPalin[2501][2501];

int minPalin(int start, int end){
	int &ret = cache[start][end];
	if(ret != -1) return ret;
	if(start == end) return ret = 0;
	if(start == end-1){
		isPalin[start][end] = true;
		return ret = 1;
	}

	bool flag;
	ret = minPalin(start+1, end) + 1;
	for(int i=start; i<end; i++){
		if(S[start] != S[i]) continue;
		if(!isPalin[start][i+1]){
			flag = true;
			for(int j=1; j*2<i-start; j++){
				if(S[start+j] != S[i-j]){
					flag = false;
					break;
				}
			}
			if(!flag) continue;
			isPalin[start][i+1] = true;
		}
		ret = min(ret, minPalin(i+1, end)+1);
	}
	return ret;
}

int main(){
	
	scanf("%s", S);
	memset(cache, -1, sizeof(int)*2501*2501);
	printf("%d\n", minPalin(0, strlen(S)) );

	return 0;
}