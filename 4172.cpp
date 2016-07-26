#include <cstdio>
#include <cmath>
using namespace std;

#define MOD 1000000

int cache[1000001] = {1};

int X(int i){
	int &ret = cache[i];
	if(ret) return ret;
	ret = X(i-sqrt(i)) + X(log(i)) + X(i*sin(i)*sin(i));
	return ret %= MOD;
}

int main(){

	int i;
	while(1){
		scanf("%d", &i);
		if(i == -1) break;
		printf("%d\n", X(i));
	}

	return 0;
}