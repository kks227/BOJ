#include <iostream>
using namespace std;

int map[52][52];

void BFS(int p, int q){
	if(map[p][q] != 1) return;
	map[p][q] = 2;
	BFS(p-1, q-1);
	BFS(p-1, q);
	BFS(p-1, q+1);
	BFS(p, q-1);
	BFS(p, q+1);
	BFS(p+1, q-1);
	BFS(p+1, q);
	BFS(p+1, q+1);
}

int main(){

	int w, h;
	int island;
	while(1){
		cin >> w >> h;
		if(w==h && w==0) break;
		for(int i=1; i<=h; i++)
			for(int j=1; j<=w; j++)
				cin >> map[i][j];
		for(int i=0; i<=h+1; i++)
			map[i][0] = map[i][w+1] = 3;
		for(int j=0; j<=w+1; j++)
			map[0][j] = map[h+1][j] = 3;

		island = 0;
		for(int i=1; i<=h; i++){
			for(int j=1; j<=w; j++){
				if(map[i][j] == 1){
					island++;
					BFS(i, j);
				}
			}
		}
		cout << island << endl;
	}

    return 0;
}