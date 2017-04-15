#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
const char dc[4] = {'U', 'D', 'L', 'R'};

int main(){
	int T;
	cin >> T;
	for(int t=0; t<T; t++){
		int R, C;
		char m[10][10];
		cin >> R >> C;
		vector<int> S;
		for(int i=0; i<R; i++){
			cin.get();
			for(int j=0; j<C; j++){
				m[i][j] = cin.get();
				if(m[i][j] == '.') S.push_back(i*10+j);
			}
		}

		map<vector<int>, string> M;
		M[S] = "";
		queue<vector<int>> Q;
		Q.push(S);
		bool success = false;
		for(int p=0; p<10; p++){
			int qSize = Q.size();
			for(int q=0; q<qSize; q++){
				vector<int> curr = Q.front();
				Q.pop();
				string path = M[curr];
				path.push_back(' ');

				for(int d=0; d<4; d++){
					path[p] = dc[d];
					vector<int> next;
					for(int pos: curr){
						int r = pos/10, c = pos%10;
						for(; m[r][c]=='.'; r+=roff[d], c+=coff[d]);
						if(m[r][c] == '#') next.push_back((r-roff[d])*10 + c-coff[d]);
					}
					if(next.empty()){
						cout << path << endl;
						success = true;
						break;
					}
					auto iter = M.find(next);
					if(iter == M.end()){
						M[next] = path;
						Q.push(next);
					}
				}
				if(success) break;
			}
			if(success) break;
		}
		if(!success) cout << "XHAE" << endl;
	}
}