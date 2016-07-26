#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){

	int result = 0;
	string line;
	for(int i=0; i<4; i++){
		cin >> line;
		for(int j=0; j<4; j++){
			if(line[j] == '.') continue;
			result += abs((line[j]-'A')/4 - i) + abs((line[j]-'A')%4 - j);
		}
	}
	cout << result << endl;

	return 0;
}