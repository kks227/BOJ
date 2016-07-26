#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){

	int X, n, p, q, sum;
	cin >> X;
	for(n=1, sum=0; sum<X; n++){
		sum += n;
	}
	q = n-1-sum+X;
	p = n-q;
	if(n%2 == 0) swap(p, q);
	cout << q << '/' << p << endl;

	return 0;
}