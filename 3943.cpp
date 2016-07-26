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
	int T, N;
	scanf("%d", &T);
	cache[1] = 1;
	for(int t=0; t<T; t++){
		scanf("%d", &N);
		printf("%d\n", maxValue(N));
	}
}