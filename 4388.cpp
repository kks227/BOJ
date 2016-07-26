#include <iostream>
using namespace std;

int main(){

	int a, b, c, carry;
	while(1){
		cin >> a >> b;
		if(a==0 && b==0) break;

		carry = c = 0;
		while(a || b){
			if(a%10 + b%10 + c >= 10){
				carry++;
				c = 1;
			}
			else c = 0;
			a /= 10;
			b /= 10;
		}
		cout << carry << endl;
	}

	return 0;
}