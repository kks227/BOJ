#include <iostream>
#include <string>
using namespace std;

int main(){

	int len;
	string line;
	cin >> line;
	len = line.size();
	for(int i=0; i<len; i++)
		line[i] ^= 32;
	cout << line << endl;

	return 0;
}