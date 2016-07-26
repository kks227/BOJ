#include <iostream>
#include <string>
using namespace std;

int main(){

	int T, len;
	double val;
	string exp;
	cin >> T;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for(int i=0; i<T; i++){
		cin >> val;
		getline(cin, exp);
		len = exp.length();
		for(int j=0; j<len; j++){
			switch(exp[j]){
			case '@':
				val *= 3;
				break;
			case '%':
				val += 5;
				break;
			case '#':
				val -= 7;
			}
		}
		cout << val << endl;
	}
 
    return 0;
}