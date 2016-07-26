#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string A, B;
	int aLen, bLen;
	char op;
	cin >> A >> op >> B;
	aLen = A.length();
	bLen = B.length();
	if(op == '+'){
		if(aLen == bLen){
			cout << '2';
			for(int i=0; i<aLen-1; i++)
				cout << '0';
		}
		else{
			if(aLen < bLen){
				swap(A, B);
				swap(aLen, bLen);
			}
			cout << '1';
			for(int i=0; i<aLen-bLen-1; i++)
				cout << '0';
			cout << '1';
			for(int i=0; i<bLen-1; i++)
				cout << '0';
		}
	}
	else{
		cout << '1';
		for(int i=0; i<aLen+bLen-2; i++)
			cout << '0';
	}

	cout << endl;

	return 0;
}