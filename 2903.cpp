#include <iostream>
using namespace std;

int main(){

	int N, current=2;
	cin >> N;
	for(int i=0; i<N; i++)
		current = current*2-1;
	cout << current*current << endl;

	return 0;
}