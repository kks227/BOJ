#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int DEPTH = 5;

struct Node{
	int A[20][20];
	Node(){ memset(A, 0, sizeof(A)); }
	Node(const Node& O){ memcpy(A, O.A, sizeof(A)); }
};

int N, result, depth;

void dfs(Node curr){
	for(int dir=0; dir<4; dir++){
		Node next(curr);
		int d = (dir<2 ? -1 : 1), s = (d>0 ? N-1 : 0), m = 1;
		bool changed = false;
		if(dir%2){
			for(int c=0; c<N; c++){
				int f = s+d; // end of full cells
				bool merged = false;
				for(int r=s, k=0; k<N; r-=d, k++){
					if(!next.A[r][c]) continue;

					if(!merged && f >= 0 && f < N && next.A[f][c] == next.A[r][c]){
						next.A[f][c] *= 2;
						merged = changed = true;
						result = max(result, next.A[f][c]);
					}
					else{
						next.A[f-=d][c] = next.A[r][c];
						merged = false;
					}
					m = max(m, next.A[f][c]);
					if(f != r){
						next.A[r][c] = 0;
						changed = true;
					}
				}
			}
		}
		else{
			for(int r=0; r<N; r++){
				int f = s+d; // end of full cells
				bool merged = false;
				for(int c=s, k=0; k<N; c-=d, k++){
					if(!next.A[r][c]) continue;

					if(!merged && f >= 0 && f < N && next.A[r][f] == next.A[r][c]){
						next.A[r][f] *= 2;
						merged = changed = true;
						result = max(result, next.A[r][f]);
					}
					else{
						next.A[r][f-=d] = next.A[r][c];
						merged = false;
					}
					m = max(m, next.A[r][f]);
					if(f != c){
						next.A[r][c] = 0;
						changed = true;
					}
				}
			}
		}
		if(depth < DEPTH-1 && result/m < 1<<DEPTH-depth-1 && changed){
			depth++;
			dfs(next);
			depth--;
		}
	}
}

int main(){
	Node S;
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			scanf("%d", &S.A[i][j]);
			result = max(result, S.A[i][j]);
		}
	}
	dfs(S);
	printf("%d\n", result);
}