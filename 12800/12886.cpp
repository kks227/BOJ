#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 751;
const int p[3][3] = {0, 1, 2, 0, 2, 1, 1, 2, 0};

int main(){
	int A[3];
	scanf("%d %d %d", A, A+1, A+2);
	if((A[0]+A[1]+A[2])%3 > 0){
		puts("0");
		return 0;
	}
	int sum = (A[0]+A[1]+A[2]);
	sort(A, A+3);
	bool visited[MAX][MAX] = {false,};
	visited[A[0]][A[1]] = true;
	queue<int> Q;
	Q.push(A[0]*MAX + A[1]);
	while(!Q.empty()){
		int curr[3] = {Q.front()/MAX, Q.front()%MAX};
		curr[2] = sum - curr[0] - curr[1];
		Q.pop();
		for(int i = 0; i < 3; ++i){
			if(curr[p[i][0]] == curr[p[i][1]]) continue;
			int next[3];
			next[p[i][0]] = curr[p[i][0]] * 2;
			next[p[i][1]] = curr[p[i][1]] - curr[p[i][0]];
			next[p[i][2]] = curr[p[i][2]];
			sort(next, next+3);
			if(!visited[next[0]][next[1]]){
				visited[next[0]][next[1]] = true;
				Q.push(next[0]*MAX + next[1]);
			}
		}
	}
	puts(visited[sum/3][sum/3] ? "1" : "0");
}