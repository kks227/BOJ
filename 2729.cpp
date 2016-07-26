#include <iostream>
#include <string>
#include <stack>
using namespace std;

string trim(string binary){
	int len = binary.length();
	int i;
	for(i=0; i<len; i++)
		if(binary[i] == '1') break;
	if(i == len) return "0";
	return binary.substr(i);
}

int main(){

	int T;
	cin >> T;
	for(int k=0; k<T; k++){
		string a, b;
		cin >> a >> b;
		a = trim(a);
		b = trim(b);
		int i = a.length()-1;
		int j = b.length()-1;
		int temp;
		bool carry = false;
		stack<bool> binary;

		while(i>=0 || j>=0 || carry){
			temp = ((i>=0)?a[i--]-'0':0) + ((j>=0)?b[j--]-'0':0) + carry;
			carry = (temp>=2);
			binary.push(temp%2);
		}

		while(!binary.empty()){
			cout << (int)binary.top();
			binary.pop();
		}
		cout << endl;
	}

	return 0;
}