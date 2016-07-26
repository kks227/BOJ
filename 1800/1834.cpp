#include <iostream>
using namespace std;

int main(){

	long long N, result;
	cin >> N;
	result = (N-1)*N/2;
	result *= (N+1);
	cout << result << endl;

	return 0;
}