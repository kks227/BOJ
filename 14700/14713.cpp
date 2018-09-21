#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main(){
	int N, pos[100] = {0};
	cin >> N;
	cin.ignore(1024, '\n');
	vector<string> S[100];
	unordered_map<string, int> contain;
	string line, word;
	stringstream ss;
	for(int i=0; i<N; i++){
		getline(cin, line);
		ss = stringstream(line);
		while(ss >> word){
			S[i].push_back(word);
			contain[word] = i;
		}
	}

	bool result = true;
	getline(cin, line);
	ss = stringstream(line);
	while(ss >> word){
		if(contain.find(word) == contain.end()){
			result = false;
			break;
		}
		int k = contain[word];
		if(pos[k] == S[k].size() || S[k][pos[k]] != word){
			result = false;
			break;
		}
		pos[contain[word]]++;
	}
	for(int i=0; i<N; i++)
		if(pos[i] != S[i].size()) result = false;
	cout << (result ? "Possible" : "Impossible") << endl;
}