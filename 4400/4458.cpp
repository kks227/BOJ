#include <iostream>
#include <string>
using namespace std;

#define DIF ('a'-'A')

int main(){

	int N;
	cin >> N;
	string sentence;
	cin.ignore(1000, '\n');
	for(int i=0; i<N; i++){
		getline(cin, sentence);
		if(islower(sentence[0])) sentence[0] -= DIF;
		cout << sentence << endl;
	}

	return 0;
}