#include <iostream>
#include <string>
using namespace std;

int main(){

	int T, len, sum;
	cin >> T;
	string S1, S2;
	for(int i=0; i<T; i++){
		cin >> S1 >> S2;
		sum = 0;
		len = S1.size();
		for(int j=0; j<len; j++)
			sum += S1[j]!=S2[j];
		cout << "Hamming distance is " << sum << '.' << endl;
	}

	return 0;
}