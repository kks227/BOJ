#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverse(string str, int start, int end){
	string result = "";
	for(int i = end-1; i >= start; --i)
		result += str[i];
	return result;
}

int main(){
	string input, temp, result(51, 'z');
	cin >> input;
	int len = input.length();
	for(int i = 1; i < len-1; ++i)
		for(int j = i+1; j < len; ++j)
			result = min(reverse(input, 0, i) + reverse(input, i, j) + reverse(input, j, len), result);
	cout << result << endl;
}