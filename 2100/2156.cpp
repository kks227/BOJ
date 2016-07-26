#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int N;
int wine[10000];
int cache[10001];

int maxWine(int start){
	int& ret = cache[start];
	if(ret != -1) return ret;
	if(start == N) return ret = 0;
	if(start == N-1) return ret = wine[N-1];
	if(start == N-2) return ret = wine[N-2] + wine[N-1];
	if(start == N-3) return ret = wine[N-3] + max(wine[N-1], wine[N-2]);
	if(start == N-4) return ret = wine[N-4] + wine[N-1] + max(wine[N-2], wine[N-3]);

	ret = max(maxWine(start+2), maxWine(start+3));
	ret = max(ret, wine[start+1] + max(maxWine(start+3), maxWine(start+4)));
	return ret += wine[start];
}

int main(){
	
	cin >> N;
	memset(cache, -1, sizeof(int)*10001);
	for(int i=0; i<N; i++)
		cin >> wine[i];
	cout << max(maxWine(0), maxWine(1)) << endl;

	return 0;
}