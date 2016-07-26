#include <iostream>
using namespace std;

int n;
int cache[1001];
int boxSize[1001];

int maxCount(int currentPos){
	int& ret = cache[currentPos];
	if(ret) return ret;
	int val;
	ret = 1;
	for(int i=currentPos+1; i<=n; i++){
		if(boxSize[currentPos] < boxSize[i]){
			val = maxCount(i)+1;
			if(ret < val) ret = val;
		}
	}
	return ret;
}

int main(){

	cin >> n;
	boxSize[0] = 0;
	for(int i=0; i<n; i++)
		cin >> boxSize[i+1];

	cout << maxCount(0)-1 << endl;

	return 0;
}