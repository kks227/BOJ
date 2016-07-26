#include <iostream>
using namespace std;

int main(){

	int A, B, C, D;
	int time;
	cin >> A >> B >> C >> D;
	time = A*3600+B*60+C+D;
	time %= 86400;
	cout << time/3600 << ' ';
	time %= 3600;
	cout << time/60 << ' ' << time%60 << endl;

    return 0;
}