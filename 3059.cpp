#include <iostream>
#include <string>
#include <set>
using namespace std;

int main(){

	int T;
	cin >> T;
	string line;
	int sum, len;
	set<char> exist;
	for(int i=0; i<T; i++){
		cin >> line;
		sum = 0;
		len = line.size();
		exist.clear();
		for(char c='A'; c<='Z'; c++)
			exist.insert(c);
		for(int j=0; j<len; j++)
			exist.erase(line[j]);
		for(set<char>::iterator iter=exist.begin(); iter!=exist.end(); iter++)
			sum += (*iter);
		cout << sum << endl;
	}

	return 0;
}