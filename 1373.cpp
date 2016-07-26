#include <iostream>
#include <string>
using namespace std;

int main(){

	string binary;
	cin >> binary;
	int size = binary.length();
	if(size == 1) cout << binary;
	else{
		if(size%3 == 2){
			if(binary[1] == '0') cout << 2;
			else cout << 3;
		}
		else if(size%3 == 1){
			cout << 1;
		}
		for(int i=size%3; i<size; i+=3){
			cout << (binary[i]-'0')*4 + (binary[i+1]-'0')*2 + binary[i+2]-'0';
		}
	}
	cout << endl;

	return 0;
}