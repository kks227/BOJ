#include <iostream>
using namespace std;

int main(){

	int m, n, current, result;
	cin >> m >> n;
	result = m*n;
	current = n;

	for(int i=0; i<3; i++){
		cout << m*(n%10) << endl;
		n /= 10;
	}
	cout << result << endl;

    return 0;
}