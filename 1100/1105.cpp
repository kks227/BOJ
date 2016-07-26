#include <iostream>
#include <cmath>
using namespace std;

int min8(int m, int n){
	int dm = (m>0)?log10(1.0*m):0;
	int dn = (n>0)?log10(1.0*n):0;
	if(dm != dn) return 0;
	if(dm == 0) return (m==n && m==8);
	int p10 = 1;
	for(int i=0; i<dm; i++)
		p10 *= 10;
	int pm = m/p10;
	int pn = n/p10;
	if(pm != pn) return 0;
	if(pm == 8) return 1+min8(m%p10, n%p10);
	return min8(m%p10, n%p10);
}

int main(){

	int L, R;
	cin >> L >> R;
	cout << min8(L, R) << endl;

    return 0;
}