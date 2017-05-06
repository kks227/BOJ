#include <cstdio>
#include <cstring>
#include <queue>
#include <set>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int N;

struct Node{
	int r[5], c[5];
	Node(){}
	Node(const Node &O){
		memcpy(r, O.r, sizeof(r));
		memcpy(c, O.c, sizeof(c));
	}
	void initialize(){
		N = 0;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(getchar() == '*'){
					r[N] = i;
					c[N] = j;
					N++;
				}
			}
			getchar();
		}
	}
	bool operator <(const Node &O)const{
		for(int i=0; i<N; i++){
			if(r[i] != O.r[i]) return (r[i] < O.r[i]);
			if(c[i] != O.c[i]) return (c[i] < O.c[i]);
		}
		return false;
	}
	bool operator ==(const Node &O)const{
		for(int i=0; i<N; i++){
			if(r[i] != O.r[i]) return false;
			if(c[i] != O.c[i]) return false;
		}
		return true;
	}
};

int main(){
	Node S;
	S.initialize();
	set<Node> visited;
	visited.insert(S);
	queue<Node> Q;
	Q.push(S);
	for(int result=0; ; result++){
		int qSize = Q.size();
		for(int i=0; i<qSize; i++){
			Node curr = Q.front();
			Q.pop();

			queue<int> checkQ;
			checkQ.push(curr.r[0]*5 + curr.c[0]);
			bool map[5][5] = {0}, checkV[5][5] = {0};
			checkV[curr.r[0]][curr.c[0]] = true;
			int cnt = 0;
			for(int i=0; i<N; i++)
				map[curr.r[i]][curr.c[i]] = true;
			while(!checkQ.empty()){
				int r = checkQ.front()/5, c = checkQ.front()%5;
				checkQ.pop();
				cnt++;

				for(int d=0; d<4; d++){
					int nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || !map[nr][nc] || checkV[nr][nc]) continue;
					checkQ.push(nr*5 + nc);
					checkV[nr][nc] = true;
				}
			}
			if(cnt == N){
				printf("%d\n", result);
				return 0;
			}

			for(int j=0; j<N; j++){
				for(int d=0; d<4; d++){
					Node next(curr);
					int r = next.r[j], c = next.c[j], nr = r+roff[d], nc = c+coff[d];
					if(nr < 0 || nr >= 5 || nc < 0 || nc >= 5 || map[nr][nc]) continue;
					next.r[j] = nr; next.c[j] = nc;
					if(visited.find(next) == visited.end()){
						visited.insert(next);
						Q.push(next);
					}
				}
			}
		}
	}
}