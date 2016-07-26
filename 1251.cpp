#include <iostream>
#include <string>
using namespace std;

string reverse(string str, int start, int end){
	string result = "";
	for(int i=end-1; i>=start; i--)
		result += str[i];
	return result;
}

int main(){

	string input, temp, min;
	cin >> input;
	min = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";

	int len = input.length();
	for(int i=1; i<len-1; i++){
		for(int j=i+1; j<len; j++){
			temp = reverse(input, 0, i) + reverse(input, i, j) + reverse(input, j, len);
			if(temp < min) min = temp;
		}
	}
	cout << min << endl;

	return 0;
}