#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 12;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<string, bool> Node;

struct Trie{
	bool output;
	Trie* go[MAX];
	Trie(): output(false){ fill(go, go+MAX, nullptr); }
	~Trie(){
		for(int i = 0; i < MAX; ++i)
			if(go[i]) delete go[i];
	}
	void insert(string &s, int len, int pos = 0){
		if(pos == len){
			output = true;
			return;
		}
		if(!go[s[pos]]) go[s[pos]] = new Trie;
		go[s[pos]]->insert(s, len, pos+1);
	}
	bool find(string &s, int len, int pos = 0){
		if(pos == len) return output;
		if(!go[s[pos]]) return false;
		return go[s[pos]]->find(s, len, pos+1);
	}
};

inline bool isStable(int R, int C, int K, int r0, int c0, char map[MAX][MAX]){
	bool visited[MAX][MAX] = {false,};
	queue<int> Q;
	visited[r0][c0] = true;
	Q.push(r0*MAX + c0);
	int cnt = 0;
	while(!Q.empty()){
		int r = Q.front()/MAX, c = Q.front()%MAX; Q.pop();
		++cnt;
		for(int d = 0; d < 4; ++d){
			int nr = r+roff[d], nc = c+coff[d];
			if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != 'o') continue;
			if(!visited[nr][nc]){
				visited[nr][nc] = true;
				Q.push(nr*MAX + nc);
			}
		}
	}
	return (cnt == K);
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t){
		int R, C, K = 0;
		bool goal[MAX][MAX] = {false,};
		char map[MAX][MAX];
		string s;
		scanf("%d %d", &R, &C);
		for(int i = 0; i < R; ++i){
			getchar();
			for(int j = 0; j < C; ++j){
				map[i][j] = getchar();
				if(map[i][j] == 'x' || map[i][j] == 'w'){
					goal[i][j] = true;
					++K;
				}
				if(map[i][j] == 'o' || map[i][j] == 'w'){
					s.push_back(i);
					s.push_back(j);
				}
				if(map[i][j] != '#') map[i][j] = '.';
			}
		}

		queue<Node> Q;
		Trie visited;
		Q.push(Node(s, true));
		visited.insert(s, K*2);
		int result = -1;
		for(int i = 0; !Q.empty() && result == -1; ++i){
			int qSize = Q.size();
			for(int j = 0; j < qSize; ++j){
				string curr = Q.front().first;
				bool currStable = Q.front().second;
				Q.pop();
				bool flag = true;
				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					map[r][c] = 'o';
					if(!goal[r][c]) flag = false;
				}
				if(flag){
					result = i;
					break;
				}

				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					for(int d = 0; d < 4; ++d){
						int nr = r+roff[d], nc = c+coff[d], pr = r-roff[d], pc = c-coff[d];
						if(nr < 0 || nr >= R || nc < 0 || nc >= C || map[nr][nc] != '.') continue;
						if(pr < 0 || pr >= R || pc < 0 || pc >= C || map[pr][pc] != '.') continue;
						string next(curr);
						next[k*2] = nr; next[k*2+1] = nc;
						if(visited.find(next, K*2)) continue;

						swap(map[r][c], map[nr][nc]);
						bool nextStable = isStable(R, C, K, nr, nc, map);
						if(currStable || nextStable){
							Q.push(Node(next, nextStable));
							visited.insert(next, K*2);
						}
						swap(map[r][c], map[nr][nc]);
					}
				}

				for(int k = 0; k < K; ++k){
					int r = curr[k*2], c = curr[k*2+1];
					map[r][c] = '.';
				}
			}
		}
		printf("Case #%d: %d\n", t, result);
	}
}