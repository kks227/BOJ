#include <iostream>
using namespace std;

int cache[100001][3];

int zoo(int row, int prev){
	int& ret = cache[row][prev];
	if(ret) return ret;
	if(row == 0) return (ret = 1);
	ret = zoo(row-1, 0);
	if(prev != 1) ret += zoo(row-1, 1);
	if(prev != 2) ret += zoo(row-1, 2);
	ret %= 9901;
	return ret;
}

int main(){

	int N;
	cin >> N;
	cout << zoo(N, 0) << endl;

	return 0;
}