#include <iostream>
using namespace std;

int main(){

	int N;
	cin >> N;
	int sum = 1, cnt = 1;
	while(sum < N){
		sum = 3*cnt*(cnt+1)+1;
		cnt++;
	}
	cout << cnt << endl;

	return 0;
}