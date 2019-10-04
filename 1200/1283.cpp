#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
const int MAX = 30;

int main(){
	int N;
	cin >> N;
	bool used[26] = {false,};
	cin.ignore(1024, '\n');
	for(int i = 0; i < N; ++i){
		string line, word;
		getline(cin, line);
		stringstream ss(line);
		vector<string> words;
		while(ss >> word)
			words.push_back(word);

		int r1 = -1;
		for(int j = 0; j < words.size(); ++j){
			string &w = words[j];
			int k = w[0] - (w[0] <= 'Z' ? 'A' : 'a');
			if(!used[k]){
				r1 = j;
				used[k] = true;
				break;
			}
		}
		if(r1 != -1){
			for(int j = 0; j < words.size(); ++j){
				string &w = words[j];
				if(r1 == j) cout << '[' << w[0] << ']' << w.substr(1);
				else cout << w;
				cout << (j+1 == words.size() ? '\n' : ' ');
			}
			continue;
		}

		int r2 = -1;
		for(int j = 0; j < words.size(); ++j){
			string &w = words[j];
			for(int l = 1; l < w.size(); ++l){
				int k = w[l] - (w[l] <= 'Z' ? 'A' : 'a');
				if(!used[k]){
					r1 = j;
					r2 = l;
					used[k] = true;
					break;
				}
			}
			if(r2 != -1) break;
		}
		if(r1 != -1){
			for(int j = 0; j < words.size(); ++j){
				string &w = words[j];
				if(r1 == j) cout << w.substr(0, r2) << '[' << w[r2] << ']' << w.substr(r2+1);
				else cout << w;
				cout << (j+1 == words.size() ? '\n' : ' ');
			}
			continue;
		}

		for(int j = 0; j < words.size(); ++j)
			cout << words[j] << (j+1 == words.size() ? '\n' : ' ');
	}
}