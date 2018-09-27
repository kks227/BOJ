#include <cstdio>
#include <algorithm>
using namespace std;

int N, P[2][50], W[2][50], PJ, WJ, A[50], B[50];
bool visited[50];

bool dfs(int a){
	visited[a] = true;
	for(int b=0; b<N; b++){
		bool flag = false;
		if(b < PJ && b < WJ) // sum of two ability
			flag = (P[0][b] + W[0][b] < P[1][a] + W[1][a]);
		else if(PJ <= b && (b < WJ || WJ < PJ)) // only power
			flag = (P[0][b] < P[1][a]);
		else // only wisdom
			flag = (W[0][b] < W[1][a]);
		if(!flag) continue;

		if(B[b] == -1 || !visited[B[b]] && dfs(B[b])){
			A[a] = b;
			B[b] = a;
			return true;
		}
	}
	return false;
}



int main(){
	scanf("%d", &N);
	for(int i=0; i<2; i++)
		for(int j=0; j<N; j++)
			scanf("%d %d", &P[i][j], &W[i][j]);

	int rJoker = 0, rVal = -1, result[50];
	for(PJ=0; PJ<N; PJ++){
		for(WJ=0; WJ<N; WJ++){
			// A for tataky, B for puyoholic (matching: a wins b)
			fill(A, A+N, -1);
			fill(B, B+N, -1);
			int cnt = 0;
			for(int i=0; i<N; i++){
				if(A[i] == -1){
					fill(visited, visited+N, false);
					if(dfs(i)) cnt++;
				}
			}
			if(rVal < cnt){
				rJoker = PJ+1;
				rVal = cnt;
				bool used[50] = {false,};
				fill(result, result+N, 0);
				for(int i=0; i<N; i++){
					if(B[i] != -1){
						result[i] = B[i]+1;
						used[B[i]] = true;
					}
				}
				for(int i=0, j=0; i<N; i++){
					if(result[i] == 0){
						while(used[j]) ++j;
						result[i] = ++j;
					}
				}
			}
		}
	}
	printf("%d\n", rJoker);
	for(int i=0; i<N; i++)
		printf("%d ", result[i]);
}