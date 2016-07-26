#include <iostream>
using namespace std;
 
int main(){
 
    int A, B, C;
    int time;
    cin >> A >> B;
    time = A*60+B-45;
	time += 1440;
    time %= 1440;
    cout << time/60 << ' ' << time%60 << endl;
 
    return 0;
}