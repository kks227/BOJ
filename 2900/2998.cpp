#include <iostream>
#include <string>
using namespace std;

int main(){

	string binary;
	cin >> binary;
	int len = binary.length();
	if(len%3 == 1) binary = "00" + binary;
	else if(len%3 == 2) binary = "0" + binary;
	len = binary.length() / 3;

	for(int i=0; i<len; i++)
		cout << (4*(binary[i*3]-'0') + 2*(binary[i*3+1]-'0') + binary[i*3+2]-'0');
	cout << endl;

    return 0;
}