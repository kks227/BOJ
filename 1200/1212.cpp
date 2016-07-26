#include <iostream>
#include <string>
using namespace std;

int main(){

	string oct;
	string bin_init[8] = {"0", "1", "10", "11", "100", "101", "110", "111"};
	string bin[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
	cin >> oct;
	int max = oct.length();
	cout << bin_init[oct[0]-'0'];
	for(int i=1; i<max; i++)
		cout << bin[oct[i]-'0'];
	cout << endl;

    return 0;
}