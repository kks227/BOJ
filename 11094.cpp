#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin >> T;
	cin.ignore(1, '\n');
	for(int t=0; t<T; t++){
		string line;
		getline(cin, line);
		if(line.substr(0, 10) == "Simon says") cout << line.substr(10) << endl;
	}
}