#include <iostream>
using namespace std;

int main(){

	int A, B;
	cin >> A >> B;

	int i, j, k;
	for(i=1, j=1, k=1; i<A; i++){
		j++;
		if(j > k){
			j = 1;
			k++;
		}
	}
	int sum = 0;
	for(; i<=B; i++){
		sum += k;
		j++;
		if(j > k){
			j = 1;
			k++;
		}
	}
	cout << sum << endl;
 
    return 0;
}