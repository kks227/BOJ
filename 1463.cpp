#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int cache[1000001];

int leastOperation(int n){
	int& ret = cache[n];
	if(ret != -1) return ret;
	if(n == 1) return ret=0;

	ret = leastOperation(n-1) + 1;
	if(n%3 == 0) ret = min(ret, leastOperation(n/3) + 1);
	if(n%2 == 0) ret = min(ret, leastOperation(n/2) + 1);
	return ret;
}

int main(){

	int N;
	cin >> N;
	memset(cache, -1, sizeof(int)*1000001);
	cout << leastOperation(N) << endl;

	return 0;
}