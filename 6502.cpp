#include <iostream>
#include <algorithm>
using namespace std;

int main(){

	int r, w, l, cnt=1;
	while(1){
		cin >> r;
		if(r==0) break;

		cin >> w >> l;
		cout << "Pizza " << cnt;
		if(w*w+l*l <= 4*r*r) cout << " fits on the table." << endl;
		else cout << " does not fit on the table." << endl;
		cnt++;
	}

	return 0;
}