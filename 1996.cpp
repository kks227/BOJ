#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main(){

	int xward[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int yward[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

	int N;
	int **map;
	cin >> N;
	map = new int*[N];
	for(int i=0; i<N; i++){
		map[i] = new int[N];
		memset(map[i], 0, N*sizeof(int));
	}

	string line;
	for(int i=0; i<N; i++){
		cin >> line;
		for(int j=0; j<N; j++){
			if(line[j] == '.') continue;
			for(int k=0; k<8; k++)
				if(i+yward[k]>=0 && i+yward[k]<N && j+xward[k]>=0 && j+xward[k]<N && map[i+yward[k]][j+xward[k]]!=-1)
					map[i+yward[k]][j+xward[k]] += line[j]-'0';
			map[i][j] = -1;
		}
	}

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(map[i][j] == -1) cout << '*';
			else if(map[i][j] >= 10) cout << 'M';
			else cout << map[i][j];
		}
		cout << endl;
		delete[] map[i];
	}
	delete[] map;

	return 0;
}