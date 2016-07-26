#include <iostream>
using namespace std;

int main(){

	int n;
	cin >> n;
	for(unsigned long long i=1; ; i++){
		if(n < i*(i*i*2+1)/3){
			cout << i-1 << endl;
			break;
		}
	}

	return 0;
}