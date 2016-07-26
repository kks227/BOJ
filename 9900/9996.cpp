#include <iostream>
#include <string>
using namespace std;

int main(){

	int N, len, patLen;
	bool flag;
	string pattern, S;
	cin >> N >> pattern;
	patLen = pattern.length();
	for(int i=0; i<N; i++){
		cin >> S;
		len = S.length();
		if(len < patLen-1){
			cout << "NE" << endl;
			continue;
		}
		flag = true;
		for(int j=0; pattern[j]!='*' && j<len; j++){
			if(pattern[j] != S[j]){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "NE" << endl;
			continue;
		}
		for(int j=0; pattern[patLen-j-1]!='*' && j<len; j++){
			if(pattern[patLen-j-1] != S[len-j-1]){
				flag = false;
				break;
			}
		}
		if(!flag){
			cout << "NE" << endl;
			continue;
		}
		cout << "DA" << endl;
	}

	return 0;
}