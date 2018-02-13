#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
const int roff[4] = {1, 0, -1, 0};
const int coff[4] = {0, 1, 0, -1};

int N;
char map[18][18];
string S;
unordered_set<string> db[18], result;

void dfs(int r = 0, int c = 0, bool flag = false){
	S[flag ? 2*(N-1)-r-c : r+c] = map[r][c];
	if(r+c == N-1){
		if(flag){
			if(db[r].find(S) != db[r].end())
				result.insert(S);
		}
		else db[r].insert(S);
		return;
	}
	for(int d=0; d<2; d++)
		dfs(r+roff[flag*2+d], c+coff[flag*2+d], flag);
}

int main(){
	cin >> N;
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin >> map[i][j];
	S.resize(N);
	dfs();
	dfs(N-1, N-1, true);
	cout << result.size() << endl;
}