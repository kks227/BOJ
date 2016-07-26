#include <iostream>
using namespace std;
 
int main(){

	int max, val, n;
	cin >> max;
	n = 1;
	for(int i=2; i<=9; i++){
		cin >> val;
		if(val > max){
			max = val;
			n = i;
		}
	}
	cout << max << endl << n << endl;

    return 0;
}