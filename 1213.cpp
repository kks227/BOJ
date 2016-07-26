#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	string name;
	cin >> name;

	char alpha[26] = {0};
	int len = name.length();
	bool isThereOddAlpha = false;
	char oddAlpha;

	for(int i=0; i<len; i++) alpha[name[i]-'A']++;
	for(int i=0; i<26; i++){
		if(alpha[i]%2){
			if(isThereOddAlpha){
				cout << "I'm Sorry Hansoo" << endl;
				return 0;
			}
			isThereOddAlpha = true;
			oddAlpha = i+'A';
		}
	}
	for(int i=0; i<26; i++)
		for(int j=0; j<alpha[i]/2; j++)
			cout << (char)(i+'A');
	if(isThereOddAlpha) cout << oddAlpha;
	for(int i=25; i>=0; i--)
		for(int j=0; j<alpha[i]/2; j++)
			cout << (char)(i+'A');
	cout << endl;

	return 0;
}