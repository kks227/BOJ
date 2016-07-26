#include <iostream>
using namespace std;

int main(){

	int n, min=100, sum=0;
	for(int i=0; i<7; i++){
		cin >> n;
		if(n%2){
			if(n < min) min = n;
			sum += n;
		}
	}

	if(sum == 0) cout << -1 << endl;
	else cout << sum << endl << min << endl;

    return 0;
}