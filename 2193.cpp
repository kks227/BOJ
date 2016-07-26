#include <iostream>
using namespace std;

unsigned long long cache[2][90];

unsigned long long pinary(int currentNumber, int spare){
	unsigned long long& ret = cache[currentNumber][spare];
	if(ret != -1) return ret;
	if(spare == 0) return (ret = 1);
	ret = pinary(0, spare-1);
	if(currentNumber == 0) ret += pinary(1, spare-1);
	return ret;
}

int main(){

	int N;
	cin >> N;
	for(int i=0; i<90; i++)
		cache[0][i] = cache[1][i] = -1;

	cout << pinary(1, N-1) << endl;

	return 0;
}