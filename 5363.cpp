#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void print(string s){
	cout << s << ' ';
}

int main(){

	int N;
	cin >> N;
	string line;
	stringstream ss;
	vector<string> vs;

	cin.ignore(1000, '\n');
	for(int t=0; t<N; t++){
		getline(cin, line);
		ss.str(line);
		ss.clear();
		while(!ss.eof()){
			ss >> line;
			vs.push_back(line);
		}
		rotate(vs.begin(), vs.begin()+2, vs.end());
		for_each(vs.begin(), vs.end()-1, print);
		cout << *(vs.end()-1) << endl;
		vs.clear();
	}

	return 0;
}