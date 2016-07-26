#include <iostream>
using namespace std;

int main(){

	int current = 0;
	int max = 0;
	int in, out;
	for(int i=0; i<10; i++){
		cin >> out >> in;
		current -= out;
		current += in;
		if(current > max) max = current;
	}
	cout << max << endl;

    return 0;
}