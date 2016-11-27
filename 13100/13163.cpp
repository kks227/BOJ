#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int main(){
	int N;
	cin >> N;
	cin.ignore(1024, '\n');
	for(int i=0; i<N; i++){
		string line;
		getline(cin, line);
		stringstream ss(line);
		vector<string> word;
		while(ss){
			string val;
			ss >> val;
			word.push_back(val);
		}
		word[0] = "god";
		for(auto& s: word)
			cout << s;
		cout << endl;
	}
}