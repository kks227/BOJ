#include <iostream>
using namespace std;

int main(){

	int max=0, maxi, maxj;
	int n;
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin >> n;
			if(n > max){
				max = n;
				maxi = i;
				maxj = j;
			}
		}
	}

	cout << max << endl << maxi+1 << ' ' << maxj+1 << endl;

    return 0;
}