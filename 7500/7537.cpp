#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_PIC = 100;
const int MAX_ENTRY = 500;
const int MAX_RSIZE = 1000;
const int MAX_LAYER = 1000001;

void skip(stringstream &ss, const string &t = ""){
	while(ss && (ss.peek() == ' ' || ss.peek() == '\t')) ss.get();
	for(int i = 0; i < t.size(); ++i){
		ss.get();
		while(ss && (ss.peek() == ' ' || ss.peek() == '\t')) ss.get();
	}
}

int main(){
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t){
		// file input
		int N, h[MAX_PIC], w[MAX_PIC];
		vector<string> pic[MAX_PIC];
		unordered_map<string, int> F2I; // filename to numbers
		cin >> N;
		for(int i = 0; i < N; ++i){
			string fname;
			cin >> fname >> h[i] >> w[i];
			F2I[fname] = i;
			for(int j = 0; j < h[i]; ++j){
				string line;
				cin >> line;
				pic[i].push_back(line);
			}
		}

		// entry input
		int M, x[MAX_ENTRY], y[MAX_ENTRY], fn[MAX_ENTRY], rel[MAX_ENTRY] = {0}; // -1 if absolute
		string rename[MAX_ENTRY];
		vector<int> layer[MAX_LAYER];
		unordered_map<string, int> E2I; // entryname to numbers
		set<int> LS;
		cin >> M;
		cin.ignore(1024, '\n');
		for(int i = 0; i < M; ++i){
			string line, ename, temp;
			stringstream ss;
			int layerNum;

			// entry name
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "#");
			ss >> ename;
			if(ename.back() == '{') ename.pop_back();
			E2I[ename] = i;

			// pos-x
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "pos-x:");
			ss >> x[i];

			// pos-y
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "pos-y:");
			ss >> y[i];

			// position
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "position:");
			if(ss.peek() == 'a') rel[i] = -1;
			else{
				rel[i] = 0;
				skip(ss, "relative=");
				ss >> rename[i];
				if(rename[i].back() == ';') rename[i].pop_back();
			}

			// file
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "file:");
			ss >> temp;
			if(temp.back() == ';') temp.pop_back();
			fn[i] = F2I[temp];

			// layer
			getline(cin, line);
			ss = stringstream(line);
			skip(ss, "layer:");
			ss >> layerNum;
			LS.insert(layerNum);
			layer[layerNum].push_back(i);

			// last line
			getline(cin, line);
			ss = stringstream(line);
		}

		// preprocessing: topological sort on entries
		int x0[MAX_ENTRY], y0[MAX_ENTRY], outdegree[MAX_ENTRY] = {0};
		vector<int> adj[MAX_ENTRY];
		queue<int> Q;
		for(int i = 0; i < M; ++i){
			if(rel[i] >= 0){
				rel[i] = E2I[rename[i]];
				adj[rel[i]].push_back(i);
				++outdegree[i];
			}
			else{
				x0[i] = x[i];
				y0[i] = y[i];
				Q.push(i);
			}
		}
		while(!Q.empty()){
			int curr = Q.front(); Q.pop();
			for(int next: adj[curr]){
				x0[next] = x0[curr] + x[next];
				y0[next] = y0[curr] + y[next];
				if(--outdegree[next] == 0) Q.push(next);
			}
		}

		// draw result
		char result[MAX_RSIZE][MAX_RSIZE];
		int W = 0, H = 0;
		for(int i = 0; i < MAX_RSIZE; ++i)
			fill(result[i], result[i]+MAX_RSIZE, ' ');
		for(int l: LS){
			for(int i: layer[l]){
				int j = fn[i];
				for(int r = 0; r < h[j]; ++r)
					for(int c = 0; c < w[j]; ++c)
						if(pic[j][r][c] != '.') result[y0[i]+r][x0[i]+c] = pic[j][r][c];
				W = max(x0[i] + w[j], W);
				H = max(y0[i] + h[j], H);
			}
		}

		// print result
		cout << "Scenario #" << t << ":\n";
		for(int i = 0; i < H; ++i){
			for(int j = 0; j < W; ++j)
				cout << result[i][j];
			cout << '\n';
		}
		cout << '\n';
	}
}