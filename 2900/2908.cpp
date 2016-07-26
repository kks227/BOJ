#include <iostream>
#include <string>
using namespace std;

int main(){

	int resA=0, resB=0;
	string A, B;
	cin >> A >> B;

	for(int i=2; i>=0; i--){
		resA *= 10;
		resA += A[i]-'0';
		resB *= 10;
		resB += B[i]-'0';
	}
	if(resA > resB) cout << resA << endl;
	else cout << resB << endl;

    return 0;
}