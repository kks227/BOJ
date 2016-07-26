#include <iostream>
using namespace std;
 
int main(){

	int n, sum=0;
	for(int i=0; i<5; i++){
		cin >> n;
		if(n < 40) n = 40;
		sum += n;
	}
	cout << sum/5 << endl;
 
    return 0;
}