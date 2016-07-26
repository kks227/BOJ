#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	bool cup[3] = {1};
	int N, X, Y;
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> X >> Y;
		if(X!=Y) swap(cup[X-1], cup[Y-1]);
	}
	for(int i=0; i<3; i++){
		if(cup[i]){
			cout << i+1 << endl;
			break;
		}
	}

	return 0;
}