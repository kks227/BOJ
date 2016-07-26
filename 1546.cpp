#include <iostream>
#include <algorithm>
using namespace std;
 
int main(){

	int N;
	int score[1000];
	cin >> N;
	for(int i=0; i<N; i++)
		cin >> score[i];
	sort(score, score+N);
	int max = score[N-1];
	int sum = 0;
	for(int i=0; i<N-1; i++)
		sum += score[i];
	double result = 100.0*(sum+max)/max/N;
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << result << endl;

    return 0;
}