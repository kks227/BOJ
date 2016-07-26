#include <iostream>
using namespace std;

int main(){

	long long R, G;
	cin >> R >> G;
	long long gcd=R, temp1=G, temp2;
	while(temp1){
		temp2 = gcd % temp1;
		gcd = temp1;
		temp1 = temp2;
	}
	if(gcd == 1) cout << 1 << ' ' << R << ' ' << G << endl;
	else for(long long i=1; i*i<=gcd; i++){
		if(gcd%i != 0) continue;
		cout << i << ' ' << R/i << ' ' << G/i << endl;
		if(i*i != gcd) cout << gcd/i << ' ' << R*i/gcd << ' ' << G*i/gcd << endl;
	}

	return 0;
}