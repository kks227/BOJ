#include <iostream>
#include <string>
using namespace std;

int main(){

	int N;
	cin >> N;
	string pattern, temp;
	int max;
	cin >> pattern;
	max = pattern.length();
	for(int i=1; i<N; i++){
		cin >> temp;
		for(int j=0; j<max; j++){
			if(pattern[j] == '?') continue;
			if(pattern[j] != temp[j]) pattern[j] = '?';
		}
	}
	cout << pattern << endl;

    return 0;
}