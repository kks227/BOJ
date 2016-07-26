#include <iostream>
using namespace std;

int main(){

	int X;
	cin >> X;
	int cnt = 0;
	while(X){
		cnt += (X%2);
		X /= 2;
	}
	cout << cnt << endl;

    return 0;
}