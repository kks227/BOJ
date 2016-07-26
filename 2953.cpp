#include <iostream>
using namespace std;
 
int main(){

	int max=0, winner, sum, n;
	for(int i=0; i<5; i++){
		sum = 0;
		for(int j=0; j<4; j++){
			cin >> n;
			sum += n;
		}
		if(max < sum){
			max = sum;
			winner = i;
		}
	}

	cout << winner+1 << ' ' << max << endl;
 
    return 0;
}