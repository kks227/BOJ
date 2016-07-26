#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

const int roff[6] = {-1, 0, 1, -1, 0, 1};
const int coff[6] = {-1, -1, -1, 1, 1, 1};

int A, B;
vector<int> adj[3200];
int Amatch[3200], Bmatch[3200];
bool visited[3200];

bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b: adj[a])
		if(Bmatch[b] == -1 || DFS(Bmatch[b])){
			Amatch[a] = b;
			Bmatch[b] = a;
			return true;
		}
	return false;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, M, broken = 0;
		scanf("%d %d", &N, &M);
		bool map[80][80];
		for(int i=0; i<N; i++){
			getchar();
			for(int j=0; j<M; j++)
				broken += map[i][j] = (getchar() == 'x');
		}
		int nodeNum[80][80];
		A = B = 0;
		for(int i=0; i<N; i++)
			for(int j=0; j<M; j+=2){
				adj[A].clear();
				nodeNum[i][j] = A++;
			}
		for(int i=0; i<N; i++)
			for(int j=1; j<M; j+=2)
				nodeNum[i][j] = B++;
		for(int j=0; j<M; j+=2)
			for(int i=0; i<N; i++){
				if(map[i][j]) continue;
				for(int d=0; d<6; d++){
					int ni = i + roff[d];
					int nj = j + coff[d];
					if(ni<0 || ni>=N || nj<0 || nj>=M || map[ni][nj]) continue;
					adj[nodeNum[i][j]].push_back(nodeNum[ni][nj]);
				}
			}

		int maxMatch = 0;
		memset(Amatch, -1, sizeof(Amatch));
		memset(Bmatch, -1, sizeof(Bmatch));
		for(int i=0; i<A; i++){
			memset(visited, 0, sizeof(visited));
			if(DFS(i)) maxMatch++;
		}
		printf("%d\n", N*M - broken - maxMatch);
	}
}