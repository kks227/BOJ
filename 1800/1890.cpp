#include <iostream>
#include <cstring>
using namespace std;

int N;
int map[100][100];
long long cache[100][100];

long long path(int y, int x){
	long long &ret = cache[y][x];
	if(ret != -1) return ret;
	if(y==N-1 && x==N-1) return ret=1;

	ret = 0;
	if(y+map[y][x] < N) ret += path(y+map[y][x], x);
	if(x+map[y][x] < N) ret += path(y, x+map[y][x]);
	return ret;
}

int main(){

	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	memset(cache, -1, sizeof(long long)*100*100);
	cout << path(0, 0) << endl;

	return 0;
}