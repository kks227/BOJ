#include <iostream>
#include <string>
using namespace std;

int main(){

	string S;
	cin >> S;
	int len = S.length();
	int joi=0, ioi=0;
	for(int i=0; i<len-2; i++){
		if(S[i]=='J' && S[i+1]=='O' && S[i+2]=='I') joi++;
		else if(S[i]=='I' && S[i+1]=='O' && S[i+2]=='I') ioi++;
	}
	cout << joi << endl << ioi << endl;

	return 0;
}