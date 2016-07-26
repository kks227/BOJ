#include <iostream>
using namespace std;

int Rev(int n){
	int result = 0;
	while(n){
		result *= 10;
		result += n%10;
		n /= 10;
	}
	return result;
}

int main(){

	int X, Y;
	cin >> X >> Y;
	cout << Rev(Rev(X) + Rev(Y)) << endl;

	return 0;
}