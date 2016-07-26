#include <iostream>
using namespace std;

int main(){

	int mushroom[10];
	for(int i=0; i<10; i++)
		cin >> mushroom[i];

	int sum = 0;
	for(int i=0; i<10; i++){
		if(sum + mushroom[i] >= 100){
			if(100-sum >= sum+mushroom[i]-100) sum += mushroom[i];
			break;
		}
		sum += mushroom[i];
	}
	cout << sum << endl;

	return 0;
}