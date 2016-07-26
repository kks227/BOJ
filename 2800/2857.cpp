#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){

	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

	string s, fbi="FBI";
	bool flag = true;
	for(int i=1; i<=5; i++){
		cin >> s;
		if(find_end(s.begin(), s.end(), fbi.begin(), fbi.end()) != s.end()){
			cout << i << ' ';
			flag = false;
		}
	}
	if(flag) cout << "HE GOT AWAY!" << endl;

	return 0;
}