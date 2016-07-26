#include <iostream>
using namespace std;

int main(){

	long long fibo[46] = {0, 1};
	int n;
	cin >> n;
	for(int i=2; i<=n; i++)
		fibo[i] = fibo[i-1] + fibo[i-2];
	cout << fibo[n] << endl;
	
    return 0;
}