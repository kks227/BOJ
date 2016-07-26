#include <iostream>
using namespace std;
 
int main(){

	int m, n;
	while(1){
		cin >> m >> n;
		if(m==0 && n==0) break;
		if(m > n) cout << "Yes";
		else cout << "No";
		cout << endl;
	}
 
    return 0;
}