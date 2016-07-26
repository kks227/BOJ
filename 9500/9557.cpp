#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> VS;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int N;
		cin >> N;
		VS block;
		vector<VS> sentence;
		for(int i=0; i<N; i++){
			string word;
			cin >> word;
			if(word[0] != '#'){
				if(!block.empty()){
					sentence.push_back(block);
					block.clear();
				}
				sentence.push_back(VS(1, word));
			}
			else block.push_back(word);
		}
		if(!block.empty()) sentence.push_back(block);

		reverse(sentence.begin(), sentence.end());
		for(auto& vs: sentence)
			for(auto& s: vs)
				cout << s << ' ';
		cout << endl;
	}
}