#include <iostream>
#include <string>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		cin.ignore(1000, '\n');
		string C, rule;
		getline(cin, C);
		cin >> rule;
		for(char &c: C)
			if(c != ' ') c = rule[c-'A'];
		cout << C << endl;
	}
}