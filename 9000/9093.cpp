#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	cin.get();
	for(int t=0; t<T; t++){
		string line;
		getline(cin, line);
		stringstream ss(line);
		vector<string> words;
		while(!ss.eof()){
			string word;
			ss >> word;
			reverse(word.begin(), word.end());
			words.push_back(word);
		}
		for(auto& s: words)
			cout << s << ' ';
		cout << endl;
	}
}