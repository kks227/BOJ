#include <iostream>
using namespace std;
 
int main(){

	int N;
	cin >> N;
	int score = 0;
	int add = 0;
	int ox;
	for(int i=0; i<N; i++){
		cin >> ox;
		if(ox == 0) add = 0;
		else add++;
		score += add;
	}
	cout << score << endl;

    return 0;
}