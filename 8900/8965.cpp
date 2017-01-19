#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		string S, result = "\x7F";
		cin >> S;
		for(int i=0; i<S.size(); i++)
			result = min(result, S.substr(i) + S.substr(0, i));
		cout << result << endl;
	}
}