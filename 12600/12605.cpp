#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

int main(){
	int T;
	cin >> T;
	cin.ignore(1024, '\n');
	for(int t = 1; t <= T; ++t){
		string line;
		getline(cin, line);
		stringstream ss(line);
		stack<string> S;
		while(1){
			string W;
			if(ss >> W) S.push(W);
			else break;
		}
		cout << "Case #" << t << ":";
		while(!S.empty()){
			cout << " " << S.top();
			S.pop();
		}
		cout << '\n';
	}
}