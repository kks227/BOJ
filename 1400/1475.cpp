#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int N;
	cin >> N;
	int digit[10] = {0};
	do{
		digit[N%10]++;
		N/=10;
	}while(N);

	int result = 0;
	for(int i=0; i<9; i++){
		if(i==6) continue;
		result = max(result, digit[i]);
	}
	result = max(result, (digit[6]+digit[9]+1)/2);
	cout << result << endl;

	return 0;
}