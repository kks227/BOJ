#include <iostream>
using namespace std;
 
int main(){

	int n;
	int cnt;
	char y[5] = {'E', 'A', 'B', 'C', 'D'};
	char result[3];
	for(int i=0; i<3; i++){
		cnt = 0;
		for(int j=0; j<4; j++){
			cin >> n;
			if(n == 0) cnt++;
		}
		result[i] = y[cnt];
	}
	for(int i=0; i<3; i++)
		cout << result[i] << endl;

    return 0;
}