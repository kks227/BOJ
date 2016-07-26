#include <iostream>
using namespace std;

int main(){

	int N, target;
	cin >> N >> target;
	int **arr = new int*[N+2];
	for(int i=0; i<N+2; i++){
		arr[i] = new int[N+2];
		for(int j=0; j<N+2; j++){
			if(i==0 || j==0 || i==N+1 || j==N+1) arr[i][j] = -1;
			else arr[i][j] = 0;
		}
	}

	int cnt = N*N;
	int dir = 0;
	int r, c;
	int movex[4] = {0, 1, 0, -1};
	int movey[4] = {1, 0, -1, 0};
	int y=0, x=0;
	r = c = 1;
	arr[1][1] = N*N;
	while(1){
		if(target == cnt){
			y = r;
			x = c;
		}

		if(arr[r+movey[dir]][c+movex[dir]] != 0){
			dir++;
			dir %= 4;
		}
		r += movey[dir];
		c += movex[dir];

		cnt--;
		if(cnt > 0) arr[r][c] = cnt;
		else break;
	}

	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){
			cout << arr[i][j];
			if(j==N) cout << endl;
			else cout << ' ';
		}
	}
	cout << y << ' ' << x << endl;

    return 0;
}