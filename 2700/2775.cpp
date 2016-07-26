#include <iostream>
using namespace std;

int main(){

	int T, a, b;
	cin >> T;
	int nk[15][15] = {0};
	for(int i=1; i<15; i++) nk[0][i] = i;
	for(int i=1; i<15; i++) nk[i][1] = 1;

	for(int i=0; i<T; i++){
		cin >> a >> b;
		if(nk[a][b] == 0){
			for(int floor=1; floor<=a; floor++){
				for(int room=1; room<=b; room++){
					if(nk[floor][room] != 0) continue;
					else nk[floor][room] = nk[floor][room-1] + nk[floor-1][room];
				}
			}
		}
		cout << nk[a][b] << endl;
	}

    return 0;
}