#include <iostream>
using namespace std;

int main(){

	long long N, M, dif;
	cin >> N >> M;
	dif = N-M;
	if(dif < 0) dif *= -1;
	cout << dif << endl;

    return 0;
}