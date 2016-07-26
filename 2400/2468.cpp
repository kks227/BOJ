#include <iostream>
using namespace std;

int N;
int** map;
int** sunken;

void DFS(int row, int col, int num);

int main(){

	int min = 100;
	int max = 0;
	int unsunken_max;
	int search_cnt;
	cin >> N;
	map = new int*[N];
	sunken = new int*[N];
	for(int i=0; i<N; i++){
		map[i] = new int[N];
		sunken[i] = new int[N];
		for(int j=0; j<N; j++){
			cin >> map[i][j];
			if(map[i][j] < min) min = map[i][j];
			if(map[i][j] > max) max = map[i][j];
		}
	}

	unsunken_max = 1;
	for(int i=min; i<max; i++){
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				//가라앉은 구역: -1
				if(map[j][k] <= i) sunken[j][k] = -1;
				//가라앉지 않았으며 아직 순회하지 않은 구역: 0
				else sunken[j][k] = 0;
				//순회한 구역: 1 이상
			}
		}
		/*
		cout << "수면: " << i << endl;
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(sunken[j][k] == -1) cout << 1;
				else cout << 0;
			}
			cout << endl;
		}*/
		
		search_cnt = 0;
		for(int j=0; j<N; j++){
			for(int k=0; k<N; k++){
				if(sunken[j][k] == 0){
					search_cnt++;
					DFS(j, k, search_cnt);
				}
			}
		}

	//	cout << "개수: " << search_cnt << endl << endl;
		if(search_cnt > unsunken_max) unsunken_max = search_cnt;
	}

	cout << unsunken_max << endl;

	return 0;
}

void DFS(int row, int col, int num){
	sunken[row][col] = num;
	if(row > 0 && sunken[row-1][col] == 0) DFS(row-1, col, num);
	if(row < N-1 && sunken[row+1][col] == 0) DFS(row+1, col, num);
	if(col > 0 && sunken[row][col-1] == 0) DFS(row, col-1, num);
	if(col < N-1 && sunken[row][col+1] == 0) DFS(row, col+1, num);
}