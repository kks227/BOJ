#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string line;
	getline(cin, line);
	stringstream ss(line);
	int A[10], N = 0, S;
	while(!ss.eof()){ ss >> A[N++]; }
	cin >> S;

	int cnt = 0;
	for(int i=0; i<N-1; i++){
		for(int j=i+1; j<N; j++){
			if(A[i]+A[j] == S){
				cout << A[i] << ' ' << A[j] << endl;
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}