#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	string A, B;
	cin >> B;
	reverse(B.begin(), B.end());
	A = "0000" + B;
	bool carry = false;
	int i;
	for(i=0; i<B.size(); i++){
		int val = A[i]-'0' + B[i]-'0' + carry;
		if(val >= 2){
			val -= 2;
			carry = true;
		}
		else carry = false;
		A[i] = val+'0';
	}
	for(; i<A.size(); i++){
		int val = A[i]-'0' + carry;
		if(val == 2){
			val = 0;
			carry = true;
		}
		else carry = false;
		A[i] = val+'0';
	}
	if(carry) A.push_back('1');
	reverse(A.begin(), A.end());
	cout << A << endl;
}