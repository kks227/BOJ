#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	while(1){
		int B, E;
		string line;
		cin >> B >> E;
		if(B == -1 && E == -1) break;

		cin.get();
		getline(cin, line);
		vector<string> S;

		for(int i=0; i<B; i++){
			if(line[i] == '<'){
				if(line[i+1] == '/'){
					S.pop_back();
					while(line[++i] != '>');
				}
				else{
					int j = i;
					while(line[++j] != '>');
					S.push_back(line.substr(i+1, j-i-1));
					i = j;
				}
			}
		}
		for(auto &tag: S) cout << '<' << tag << '>';

		for(int i=B; i<E; i++){
			if(line[i] == '<'){
				if(line[i+1] == '/'){
					cout << "</" << S.back() << '>';
					S.pop_back();
					while(line[++i] != '>');
				}
				else{
					int j = i;
					while(line[++j] != '>');
					S.push_back(line.substr(i+1, j-i-1));
					cout << '<' << S.back() << '>';
					i = j;
				}
			}
			else cout << line[i];
		}
		for(int i=S.size()-1; i>=0; i--) cout << "</" << S[i] << '>';
		cout << endl;
	}
}