#include <iostream>
using namespace std;

int main(){

	long long int N;
	cin >> N;
	if(N == 0){
		cout << "NO" << endl;
		return 0;
	}
	long long int fact[20] = {1,};

	int i;
	for(i=1; i<20; i++)
		fact[i] = fact[i-1] * i;

	for(i=19; i>=0; i--)
		if(N >= fact[i]) N -= fact[i];

	if(N != 0) cout << "NO" << endl;
	else cout << "YES" << endl;

	return 0;
}