#include <iostream>
using namespace std;

int gcd(int a, int b){
	int temp;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	return a;
}

int main(){

	int a, b, c, d;
	int p, q, r;
	cin >> a >> b >> c >> d;
	p = a*d + b*c;
	q = b*d;
	r = gcd(p, q);
	cout << p/r << ' ' << q/r << endl;

    return 0;
}