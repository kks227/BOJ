#include <iostream>
#include <vector>
using namespace std;
  
int main(){

	int N, n;
	cin >> N;
	vector<int> input;
	for(int i=0; i<N; i++){
		cin >> n;
		input.push_back(n);
	}
	for(int i=0; i<N; i++){
		n = input[i];
		if(n == 0){
			cout << endl << endl;
			continue;
		}
		if(n == 1){
			cout << '#' << endl << endl;
			continue;
		}
		for(int j=0; j<n; j++)
			cout << '#';
		cout << endl;
		for(int j=1; j<n-1; j++){
			cout << '#';
			for(int j=1; j<n-1; j++)
				cout << 'J';
			cout << '#' << endl;
		}
		for(int j=0; j<n; j++)
			cout << '#';
		cout << endl;

		if(i<N-1) cout << endl;
	}
  
    return 0;
}