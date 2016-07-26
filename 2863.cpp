#include <iostream>
using namespace std;

int main(){

	int A, B, C, D;
	int temp, maxcnt;
	double val, max=0;
	cin >> A >> B >> C >> D;
	for(int i=0; i<4; i++){
		val = (double)(A*D+B*C)/(C*D);
		if(max < val){
			max = val;
			maxcnt = i;
		}
		temp = A;
		A = C;
		C = D;
		D = B;
		B = temp;
	}
	cout << maxcnt << endl;

	return 0;
}