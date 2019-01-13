#include <cstdio>
#include <queue>
#include <set>
#include <tuple>
#include <algorithm>
using namespace std;
const int MAX = 20;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, -1, 0, 1};
typedef tuple<int, int, int, int, int, int> T;

struct Node{
	int r[2], c[2], d[2];
	Node(): Node(0, 0, 0, 0, 0, 0){}
	Node(int r1, int c1, int d1, int r2, int c2, int d2){
		r[0] = r1; c[0] = c1; d[0] = d1;
		r[1] = r2; c[1] = c2; d[1] = d2;
	}
	bool operator <(const Node &O)const{
		return T(r[0], c[0], d[0], r[1], c[1], d[1]) < T(O.r[0], O.c[0], O.d[0], O.r[1], O.c[1], O.d[1]);
	}
};

int main(){
	int N;
	char map[MAX][MAX];
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		getchar();
		for(int j = 0; j < N; ++j)
			map[i][j] = getchar();
	}

	set<Node> visited;
	queue<Node> Q;
	visited.insert(Node(N-1, 0, 0, N-1, 0, 3));
	Q.push(Node(N-1, 0, 0, N-1, 0, 3));
	for(int result = 0; ; ++result){
		int qSize = Q.size();
		for(int i = 0; i < qSize; ++i){
			Node curr = Q.front(); Q.pop();
			if(curr.r[0] == 0 && curr.c[0] == N-1 && curr.r[1] == 0 && curr.c[1] == N-1){
				printf("%d\n", result);
				return 0;
			}

			for(int j = -1; j <= 1; j += 2){
				Node next(curr);
				for(int k = 0; k < 2; ++k)
					next.d[k] = (4 + next.d[k] + j) % 4;
				if(visited.find(next) == visited.end()){
					visited.insert(next);
					Q.push(next);
				}
			}

			Node next(curr);
			for(int k = 0; k < 2; ++k){
				if(next.r[k] == 0 && next.c[k] == N-1) continue;
				int d = next.d[k];
				int nr = next.r[k] + roff[d], nc = next.c[k] + coff[d];
				if(nr < 0 || nr >= N || nc < 0 || nc >= N || map[nr][nc] == 'H') continue;
				next.r[k] = nr;
				next.c[k] = nc;
			}
			if(visited.find(next) == visited.end()){
				visited.insert(next);
				Q.push(next);
			}
		}
	}
}