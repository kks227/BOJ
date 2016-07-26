#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){

	int T, len;
	cin >> T;
	string line;
	set<int> digit;
	for(int i=0; i<T; i++){
		cin >> line;
		digit.clear();
		len = line.length();
		for(int j=0; j<len; j++)
			digit.insert(line[j]);
		cout << digit.size() << endl;
	}

	return 0;
}