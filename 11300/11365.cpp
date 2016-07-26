#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	while(1){
		string line;
		getline(cin, line);
		if(line == "END") break;
		reverse(line.begin(), line.end());
		cout << line << endl;
	}
}