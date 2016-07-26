#include <iostream>
#include <string>
using namespace std;

int main(){

	int T;
	cin >> T;
	string line;
	for(int i=0; i<T; i++){
		cin >> line;
		cout << line[0] << line[line.size()-1] << endl;
	}

	return 0;
}