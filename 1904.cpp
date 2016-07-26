#include <iostream>
using namespace std;

#define MOD 15746

int main(){

	int N;
	cin >> N;
	int a[3] = {2, 3};
	if(N <= 3) cout << N << endl;
	else{
		for(int i=3; i<N; i++){
			a[2] = (a[0] + a[1])%MOD;
			a[0] = a[1];
			a[1] = a[2];
		}
		cout << a[1] << endl;
	}

	return 0;
}