#include <iostream>
using namespace std;

int main(){

	int m, n;
	cin >> m >> n;

	int a=m, b=n, c;
	while(b){
		c = a%b;
		a = b;
		b = c;
	}

	cout << a << endl << m*n/a << endl;

    return 0;
}