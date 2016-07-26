#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int X, Y, N;
	double result;
	cin >> X >> Y;
	result = 1.0*X/Y;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> X >> Y;
		result = min(result, 1.0*X/Y);
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << 1000*result << endl;

	return 0;
}