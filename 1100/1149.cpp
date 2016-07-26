#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int cost[1000][3];
int cache[1000][3];
int N;

int minPaintCost(int currentHouse, int currentColor){
	int& ret = cache[currentHouse][currentColor];
	if(ret != -1) return ret;
	if(currentHouse == N-1) return ret = cost[N-1][currentColor];

	int cnt = 0;
	int eachCost[2];
	for(int i=0; i<3; i++){
		if(i == currentColor) continue;
		eachCost[cnt++] = minPaintCost(currentHouse+1, i);
	}
	ret = min(eachCost[0], eachCost[1]);
	ret += cost[currentHouse][currentColor];
	return ret;
}

int main(){

	cin >> N;
	for(int i=0; i<N; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &cost[i][j]);
			cache[i][j] = -1;
		}
	}

	int min, cur;
	for(int i=0; i<3; i++){
		cur = minPaintCost(0, i);
		if(i==0) min = cur;
		else if(min > cur) min = cur;
	}
	cout << min << endl;

	return 0;
}