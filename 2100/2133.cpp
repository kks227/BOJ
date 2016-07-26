#include <cstdio>
#include <cstring>
using namespace std;

int N, cache[30][3];

// status: OOO(0) XOO(1) XXO(2)
int tiling(int pos, int status){
	if(pos > N) return 0;
	if(pos == N) return status==0;
	int &ret = cache[pos][status];
	if(ret != -1) return ret;
	if(status == 0) return ret = tiling(pos+1, 1) + tiling(pos, 2) + tiling(pos+2, 0);
	if(status == 1) return ret = tiling(pos+1, 0) + tiling(pos+1, 2);
	return ret = tiling(pos+1, 1);
}

int main(){
	scanf("%d", &N);
	memset(cache, -1, sizeof(cache));
	printf("%d\n", N%2?0:tiling(0, 0));
}