#include <iostream>
using namespace std;

int main(){

	int A, B, C;
	int time;
	cin >> A >> B >> C;
	time = A*60+B+C;
	time %= 60*24;
	cout << time/60 << ' ' << time%60 << endl;

    return 0;
}