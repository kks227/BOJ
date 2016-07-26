#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	long long result = N;
	result = 3*result*(N+1)/2 + N + 1;
	cout << result%45678 << endl;

	return 0;
}