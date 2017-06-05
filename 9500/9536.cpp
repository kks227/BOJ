#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		vector<string> S;
		do{
			string s;
			cin >> s;
			S.push_back(s);
		}while(cin.get() != '\n');
		unordered_set<string> W;
		while(1){
			string w;
			getline(cin, w);
			if(w == "what does the fox say?") break;
			stringstream ss(w);
			for(int i=0; i<3; i++){
				string ww;
				ss >> ww;
				if(i == 2) W.insert(ww);
			}
		}
		for(string &s: S)
			if(W.find(s) == W.end()) cout << s << ' ';
		cout << endl;
	}
}