#include <cstdio>
#include <cstring>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;
const int MAX = 20000;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int R, C, cnt, scc, dfsn[MAX*2], sccNum[MAX*2];
vector<int> adj[MAX*2], active;
bool finished[MAX*2];
stack<int> S;

inline int oppo(int n){ return n%2 ? n-1 : n+1; }
inline int towerNum(int r, int c){ return (r*C+c)*4; }
inline bool valid(int r, int c){ return r>=0 && c>=0 && r<R && c<C; }

int DFS(int curr){
	dfsn[curr] = ++cnt;
	S.push(curr);
	int result = dfsn[curr];
	for(int next: adj[curr]){
		if(dfsn[next] == 0) result = min(result, DFS(next));
		else if(!finished[next]) result = min(result, dfsn[next]);
	}
	if(result >= dfsn[curr]){
		sccNum[curr] = ++scc;
		while(1){
			int family = S.top();
			S.pop();
			finished[family] = true;
			if(family == curr) break;
			sccNum[family] = sccNum[curr];
		}
	}
	return result;
}

int main(){
	char map[100][100];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++){
		getchar();
		for(int j=0; j<C; j++)
			map[i][j] = getchar();
	}
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++){
			if(map[i][j] == 'T'){
				int Tn = towerNum(i, j);
				for(int d=0; d<4; d++){
					for(int r=i+roff[d], c=j+coff[d]; valid(r, c) && map[r][c]!='#'; r+=roff[d], c+=coff[d])
						if(map[r][c] == 'T'){
							adj[Tn+d].push_back(oppo(Tn+d));
							break;
						}
				}
				active.push_back(Tn/4);
			}
			else if(map[i][j] == 'n'){
				int Tn[4] = {-1, -1, -1, -1}, Tcnt = 0;
				for(int d=0; d<4; d++){
					for(int r=i+roff[d], c=j+coff[d]; valid(r, c) && map[r][c]!='#'; r+=roff[d], c+=coff[d])
						if(map[r][c] == 'T'){
							Tn[d] = towerNum(r, c) + oppo(d);
							Tcnt++;
							break;
						}
				}
				if(Tcnt == 3){
					if(Tn[0]!=-1 && Tn[1]!=-1){
						int Tremain = Tn[2]!=-1 ? 2 : 3;
						adj[oppo(Tn[Tremain])].push_back(Tn[Tremain]);
					}
					else if(Tn[2]!=-1 && Tn[3]!=-1){
						int Tremain = Tn[0]!=-1 ? 0 : 1;
						adj[oppo(Tn[Tremain])].push_back(Tn[Tremain]);
					}
				}
				else if(Tcnt == 2){
					sort(Tn, Tn+4);
					adj[oppo(Tn[2])].push_back(Tn[3]);
					adj[oppo(Tn[3])].push_back(Tn[2]);
				}
				else{
					sort(Tn, Tn+4);
					adj[oppo(Tn[3])].push_back(Tn[3]);
				}
			}
		}

	for(int a: active)
		for(int d=0; d<4; d++)
			if(dfsn[a*4+d] == 0) DFS(a*4+d);
	int result[MAX];
	memset(result, -1, sizeof(result));
	vector<P> p;
	for(int a: active)
		for(int d=0; d<4; d++)
			p.push_back(P(sccNum[a*4+d], a*4+d));
	sort(p.begin(), p.end());
	for(int i=p.size()-1; i>=0; i--){
		int var = p[i].second;
		if(result[var/2] == -1) result[var/2] = !(var%2);
	}
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			if(map[i][j] == 'T'){
				bool verti = result[(i*C+j)*2];
				bool hori = result[(i*C+j)*2+1];
				if(verti) map[i][j] = hori ? '2' : '1';
				else map[i][j] = hori ? '3' : '4';
			}
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			putchar(map[i][j]);
		puts("");
	}
}