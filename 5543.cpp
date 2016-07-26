#include <iostream>
using namespace std;
 
int main(){

	int burger_min=2001, n;
	for(int i=0; i<3; i++){
		cin >> n;
		if(n < burger_min) burger_min = n;
	}
	int liq_min;
	cin >> liq_min >> n;
	if(n < liq_min) liq_min = n;
	cout << burger_min+liq_min - 50 << endl;
 
    return 0;
}