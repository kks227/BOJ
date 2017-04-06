#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> V;

int main(){
	int C[3];
	scanf("%d %d %d", C, C+1, C+2);
	bool visited[201][201][201] = {0};
	queue<V> Q;
	visited[0][0][C[2]] = true;
	V sv(3, 0);
	sv[2] = C[2];
	Q.push(sv);
	while(!Q.empty()){
		V curr = Q.front();
		Q.pop();
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(i == j || curr[j] == C[j]) continue;
				V next(curr);
				int d = min(curr[i], C[j]-curr[j]);
				next[i] -= d;
				next[j] += d;
				if(!visited[next[0]][next[1]][next[2]]){
					visited[next[0]][next[1]][next[2]] = true;
					Q.push(next);
				}
			}
		}
	}
	for(int i=0; i<=C[2]; i++)
		if(C[2]-i <= C[1] && visited[0][C[2]-i][i]) printf("%d ", i);
}