#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;

queue<int> mq;
bool map[102][102];

int BFS(int yStart, int xStart){
	int y, x;
	int result = 0;
	mq.push(yStart*1000 + xStart);
	while(!mq.empty()){
		y = mq.front();
		mq.pop();
		x = y%1000;
		y /= 1000;
		if(map[y][x]) continue;
		result++;
		map[y][x] = true;
		if(!map[y-1][x]) mq.push((y-1)*1000 + x);
		if(!map[y+1][x]) mq.push((y+1)*1000 + x);
		if(!map[y][x-1]) mq.push(y*1000 + x-1);
		if(!map[y][x+1]) mq.push(y*1000 + x+1);
	}
	return result;
}

int main(){

	int M, N, K, x1, y1, x2, y2;
	scanf("%d %d %d", &M, &N, &K);
	for(int i=0; i<=M+1; i++)
		map[i][0] = map[i][N+1] = true;
	for(int j=1; j<=N; j++)
		map[0][j] = map[M+1][j] = true;

	for(int i=0; i<K; i++){
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		if(x1 > x2) swap(x1, x2);
		if(y1 > y2) swap(y1, y2);
		x1 = max(x1, 0);
		y1 = max(y1, 0);
		x2 = min(x2, N);
		y2 = min(y2, M);
		for(int x=x1; x<x2; x++)
			for(int y=y1; y<y2; y++)
				map[y+1][x+1] = true;
	}

	multiset<int> area;
	int cnt = 0;
	for(int i=1; i<=M; i++){
		for(int j=1; j<=N; j++){
			if(map[i][j]) continue;
			area.insert(BFS(i, j));
			cnt++;
		}
	}
	printf("%d\n", cnt);
	int temp = 0;
	for(multiset<int>::iterator iter=area.begin(); iter!=area.end(); iter++){
		temp++;
		printf("%d%c", *iter, cnt==temp?'\n':' ');
	}

	return 0;
}