#include <iostream>
#include <sstream>
#include <string>
#include <set>
#include <cctype>
using namespace std;
const int MAX = 100;

int main(){
	int N;
	cin >> N;
	cin.ignore(1024, '\n');
	string name[MAX], line, word;
	set<string> S[MAX];
	for(int i = 0; i < N; ++i){
		getline(cin, line);
		stringstream ss(line);
		ss >> name[i];
		while(ss >> word){
			for(char &c: word)
				if(isupper(c)) c += ('a'-'A');
			S[i].insert(word);
		}
	}
	getline(cin, line);
	while(getline(cin, line)){
		string s = "";
		int result = 0;
		for(int i = 0; i < line.size(); ++i){
			char c = line[i];
			if(!isalpha(c) && c != '\'' && c != '-'){
				for(int j = 0; j < N; ++j)
					if(S[j].find(s) != S[j].end()) result = j;
				s = "";
			}
			else{
				if(isupper(c)) c += ('a'-'A');
				s.push_back(c);
			}
		}
		for(int j = 0; j < N; ++j)
			if(S[j].find(s) != S[j].end()) result = j;
		cout << name[result] << '\n';
	}
}