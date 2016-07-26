#include <iostream>
using namespace std;

int main(){

	int T, N;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> N;
		for(int i=0; N; i++){
			if(N%2) cout << i << ' ';
			N /= 2;
		}
		cout << endl;
	}

	return 0;
}