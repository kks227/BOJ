#include <iostream>
using namespace std;

int main(){

	int T, C;
	int cost[3] = {25, 10, 5};
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> C;
		for(int j=0; j<3; j++){
			cout << C/cost[j] << ' ';
			C %= cost[j];
		}
		cout << C << endl;
	}

	return 0;
}