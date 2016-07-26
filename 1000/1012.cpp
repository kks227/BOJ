#include <iostream>
using namespace std;

int map[52][52];

void BFS(int p, int q){
	if(map[p][q] != 1) return;
	map[p][q] = 2;
	BFS(p-1, q);
	BFS(p, q-1);
	BFS(p, q+1);
	BFS(p+1, q);
}

int main(){

	int T, M, N, K, X, Y;
	int wiggler;
	cin >> T;
	for(int i=0; i<T; i++){
		cin >> M >> N >> K;
        for(int j=0; j<=M+1; j++)
            map[0][j] = map[N+1][j] = 3;
        for(int j=0; j<=N+1; j++)
            map[j][0] = map[j][M+1] = 3;
        for(int j=1; j<=N; j++)
            for(int k=1; k<=M; k++)
                map[j][k] = 0;

		for(int j=0; j<K; j++){
			cin >> X >> Y;
			map[Y+1][X+1] = 1;
		}

		wiggler = 0;
        for(int j=1; j<=N; j++){
            for(int k=1; k<=M; k++){
                if(map[j][k] == 1){
                    wiggler++;
                    BFS(j, k);
                }
            }
        }
		cout << wiggler << endl;
	}

    return 0;
}