#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(){
	int T;
	cin >> T;
	cin.ignore(1024, '\n');
	for(int t=0; t<T; t++){
		string S;
		getline(cin, S);
		bool result = true;
		for(int i=0, j=S.size()-1; i<=j; i++, j--){
			if(isupper(S[i])) S[i] += 'a'-'A';
			if(isupper(S[j])) S[j] += 'a'-'A';
			if(S[i] != S[j]){
				result = false;
				break;
			}
		}
		cout << (result ? "Yes" : "No") << endl;
	}
}