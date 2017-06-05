#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(){
	map<string, char> M;
	M[".-"] = 'A';
	M["-..."] = 'B';
	M["-.-."] = 'C';
	M["-.."] = 'D';
	M["."] = 'E';
	M["..-."] = 'F';
	M["--."] = 'G';
	M["...."] = 'H';
	M[".."] = 'I';
	M[".---"] = 'J';
	M["-.-"] = 'K';
	M[".-.."] = 'L';
	M["--"] = 'M';
	M["-."] = 'N';
	M["---"] = 'O';
	M[".--."] = 'P';
	M["--.-"] = 'Q';
	M[".-."] = 'R';
	M["..."] = 'S';
	M["-"] = 'T';
	M["..-"] = 'U';
	M["...-"] = 'V';
	M[".--"] = 'W';
	M["-..-"] = 'X';
	M["-.--"] = 'Y';
	M["--.."] = 'Z';
	int T;
	cin >> T;
	for(int t=1; t<=T; t++){
		cout << "Case " << t << ": ";
		for(int i=0; i<5; i++){
			string m;
			cin >> m;
			cout << M[m];
		}
		cout << endl;
	}
}