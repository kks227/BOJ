#include <iostream>
#include <string>
using namespace std;

int main(){

	string str;
	string result = "";
	cin >> str;
	int max = str.length();
	for(int i=0; i<max; i++){
		if(str[i] >= 'A' && str[i] <= 'Z')
			result += str[i];
	}
	cout << result << endl;

	return 0;
}