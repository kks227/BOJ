#include <cstdio>
#include <cstring>
using namespace std;

char str[41];
int len, cache[40];

int cnt(int start){
	if(start == len) return 1;
	int &ret = cache[start];
	if(ret != -1) return ret;
	if(str[start] == '0') return ret = 0;
	if(start == len-1) return ret = 1;

	ret = 0;
	if(str[start] <= '2') ret += cnt(start+2);
	else if(str[start] == '3' && str[start+1] <= '4') ret += cnt(start+2);
	ret += cnt(start+1);
	return ret;
}

int main(){

	scanf("%s", str);
	len = strlen(str);
	memset(cache, -1, sizeof(int)*40);
	printf("%d\n", cnt(0));

	return 0;
}