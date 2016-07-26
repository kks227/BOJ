#include <iostream>
#include <cstring>
using namespace std;

int cache[11];

int pos(int spare){
	int& ret = cache[spare];
	if(ret) return ret;
	if(spare <= 1) return ret=1;
	ret = pos(spare-1) + pos(spare-2);
	if(spare >= 3) ret += pos(spare-3);
	return ret;
}

int main(){

	int T, n;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> n;
		memset(cache, 0, sizeof(int)*11);
		cout << pos(n) << endl;
	}

	return 0;
}