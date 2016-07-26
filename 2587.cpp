#include <iostream>
using namespace std;

int main(){

	int n[5], sum=0;
	for(int i=0; i<5; i++){
		cin >> n[i];
		sum += n[i];
	}

	int temp;
	for(int i=0; i<4; i++){
		for(int j=i+1; j<5; j++){
			if(n[i] > n[j]){
				temp = n[j];
				n[j] = n[i];
				n[i] = temp;
			}
		}
	}

	cout << sum/5 << endl << n[2] << endl;

    return 0;
}