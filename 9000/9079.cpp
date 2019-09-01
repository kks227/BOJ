#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1e9;
const int MAX_B = 9;
const int MAX = 1<<MAX_B;
const int farr[8][3] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8,
	0, 3, 6, 1, 4, 7, 2, 5, 8,
	0, 4, 8, 2, 4, 6
};

inline int flip(int n, int a, int b, int c){
	n ^= 1 << a;
	n ^= 1 << b;
	n ^= 1 << c;
	return n;
}

int main(){
	int dist[MAX];
	fill(dist, dist+MAX, INF);
	queue<int> Q;
	Q.push(0);
	Q.push(MAX-1);
	dist[0] = dist[MAX-1] = 0;
	while(!Q.empty()){
		int curr = Q.front(); Q.pop();
		for(int i = 0; i < 8; ++i){
			int next = flip(curr, farr[i][0], farr[i][1], farr[i][2]);
			if(dist[next] == INF){
				dist[next] = dist[curr] + 1;
				Q.push(next);
			}
		}
	}

	int T;
	scanf("%d", &T);
	for(int t = 0; t < T; ++t){
		int s = 0;
		for(int i = 0; i < MAX_B; ++i){
			char c;
			scanf(" %c", &c);
			if(c == 'T') s += 1<<i;
		}
		printf("%d\n", dist[s] == INF ? -1 : dist[s]);
	}
}