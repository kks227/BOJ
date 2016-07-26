#include <iostream>
using namespace std;

int main(){

	int P, N;
	double D, A, B, F;
	double H, result;
	cin >> P;
	for(int i=0; i<P; i++){
		cin >> N >> D >> A >> B >> F;
		H = D/(A+B);
		result = F * H;
		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);
		cout << N << ' ' << result << endl;
	}

	return 0;
}