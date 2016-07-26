#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){

	int n[3];
	cin >> n[0] >> n[1] >> n[2];
	sort(n, n+3);

	if(n[1]-n[0] == n[2]-n[1]) cout << 2*n[2]-n[1] << endl;
	else if(n[1]-n[0] < n[2]-n[1]) cout << (n[2]+n[1])/2 << endl;
	else cout << (n[1]+n[0])/2 << endl;

    return 0;
}