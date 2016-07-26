#include <iostream>
#include <string>
using namespace std;

int main(){

	int n;
	int col, max;
	string sentence;
	while(1){
		cin >> n;
		if(n == 0) break;
		col = 0;
		cin.ignore(1000, '\n');
		for(int i=0; i<n; i++){
			getline(cin, sentence);
			max = sentence.length();
			for(; col<max; col++){
				if(sentence[col] == ' ') break;
			}
		}
		cout << col+1 << endl;
	}

    return 0;
}