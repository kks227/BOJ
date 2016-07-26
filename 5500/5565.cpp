#include <iostream>
using namespace std;
 
int main(){

	int result, n;
	cin >> result;
	for(int i=0; i<9; i++){
		cin >> n;
		result -= n;
	}
	cout << result << endl;
 
    return 0;
}