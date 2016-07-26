#include <iostream>
#include <string>
using namespace std;

int main(){

	int T;
	cin >> T;
	
	int n, max;
	string str;
	for(int i=0; i<T; i++){
		cin >> n >> str;
		max = str.length();
		for(int j=0; j<max; j++){
			if(j == n-1) continue;
			cout << str[j];
		}
		cout << endl;
	}

    return 0;
}