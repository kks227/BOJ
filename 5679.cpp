#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> cache;

int maxValue(int n){
	map<int, int>::iterator iter;
	if((iter=cache.find(n)) != cache.end()) return iter->second;
	return cache[n] = max(n, n%2 ? maxValue(n*3+1) : maxValue(n/2));
}

int main(){
	cache[1] = 1;
	while(1){
		int H;
		scanf("%d", &H);
		if(H == 0) break;
		printf("%d\n", maxValue(H));
	}
}