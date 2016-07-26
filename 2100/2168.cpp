#include <iostream>
using namespace std;

int main(){

	int x, y;
	cin >> x >> y;
	int temp;
	if(x > y){
		temp = x;
		x = y;
		y = temp;
	}
	int a=y, b=x;
	while(b){
		temp = a%b;
		a = b;
		b = temp;
	}
	cout << x+y-a << endl;

    return 0;
}