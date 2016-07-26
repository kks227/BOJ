#include <iostream>
using namespace std;

int main(){

	int year;
	cin >> year;
	int ji = (8 + year%12)%12;
	int kan = (5 + year%10)%10;
	cout << char(ji+'A') << (kan+1)%10 << endl;

	return 0;
}