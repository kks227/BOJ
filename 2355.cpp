#include <iostream>
using namespace std;

long long sigma(long long n){
	if(n<=0) return 0;
	if(n%2) return (n+1)/2*n;
	return n/2*(n+1);
}
 
int main(){

	long long i, j;
	cin >> i >> j;
	if(i > j){
		long long temp = i;
		i = j;
		j = temp;
	}

	if(i==j) cout << i << endl;
	else if(0<=i) cout << sigma(j)-sigma(i-1) << endl;
	else if(j<=0) cout << sigma(-j-1)-sigma(-i) << endl;
	else cout << sigma(j)-sigma(-i) << endl;

    return 0;
}