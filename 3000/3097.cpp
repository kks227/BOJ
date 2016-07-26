#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int N;
	int X[30], x_sum=0;
	int Y[30], y_sum=0;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> X[i] >> Y[i];
		x_sum += X[i];
		y_sum += Y[i];
	}
	cout << x_sum << ' ' << y_sum << endl;

	int min_dist_square = pow(x_sum-X[0], 2.0) + pow(y_sum-Y[0], 2.0);
	int temp;
	for(int i=1; i<N; i++){
		temp = pow(x_sum-X[i], 2.0) + pow(y_sum-Y[i], 2.0);
		if(min_dist_square > temp) min_dist_square = temp;
	}
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << sqrt((double)min_dist_square) << endl;

	return 0;
}