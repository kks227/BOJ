#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <cctype>
#include <cstring>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX_S = 500;
const int MAX_L = 50;

int N, M = 27; // 0~25: terminal 'a'~'z', 26: start symbol
vector<vector<int>> T[MAX_S];
string sentence;
char dp[MAX_L+1][MAX_L+1][MAX_S];

bool CYK(int s, int e, int k){
	char &ret = dp[s][e][k];
	if(ret != -1) return ret;
	if(s == e) return ret = false;
	if(s+1 == e){
		if(!islower(sentence[s])) return ret = false;
		if(sentence[s]-'a' == k) return ret = true;
		for(auto &b: T[k])
			if(b.size() == 1 && sentence[s]-'a' == b[0]) return ret = true;
		return ret = false;
	}

	for(auto &b: T[k])
		if(b.size() == 2)
			for(int i = s+1; i < e; ++i)
				if(CYK(s, i, b[0]) && CYK(i, e, b[1])) return ret = true;
	return ret = false;
}

int main(){
	cin >> N;
	cin.ignore(1024, '\n');
	unordered_map<char, int> S2I;

	// input
	// START: Eliminate the start symbol from right-hand sides
	// TERM: Eliminate rules with nonsolitary terminals
	bool toEps[MAX_S] = {0};
	for(int i = 0; i < N; ++i){
		string line, dummy, rule;
		char nonterminal;
		getline(cin, line);
		stringstream ss(line);
		ss >> nonterminal >> dummy;
		if(S2I.find(nonterminal) == S2I.end()) S2I[nonterminal] = M++;
		int sn = S2I[nonterminal];
		if(i == 0) T[26].push_back(vector<int>(1, sn));

		if(ss >> rule){
			//string word = "";
			vector<int> branch;
			for(char c: rule){
				if(islower(c)){ // terminal
					branch.push_back(c-'a');
				}
				else{ // nonterminal
					if(S2I.find(c) == S2I.end()) S2I[c] = M++;
					int wn = S2I[c];
					branch.push_back(wn);
				}
			}
			T[sn].push_back(branch);
		}
		else toEps[sn] = true;
	}

	// BIN: Eliminate right-hand sides with more than 2 nonterminals
	for(int i = M-1; i >= 26; --i){
		for(auto &b: T[i]){
			int len = b.size();
			if(len <= 2) continue;

			// A -> X1 X2 ... Xn
			vector<int> newBranch;
			// A(n-2) -> X(n-1) Xn
			newBranch = vector<int>(1, b[len-2]);
			newBranch.push_back(b[len-1]);
			T[M+len-3].push_back(newBranch);
			// A(k-1) -> Xk Ak
			for(int j = 1; j < len-2; ++j){
				newBranch = vector<int>(1, b[j]);
				newBranch.push_back(M+j);
				T[M+j-1].push_back(newBranch);
			}
			// A -> X1 A1
			for(int j = 0; j < len-1; ++j)
				b.pop_back();
			b.push_back(M);
			M += len-2;
		}
	}

	// DEL: Eliminate eps-rules
	vector<int> rAdj[MAX_S];
	for(int i = 27; i < M; ++i)
		for(auto &b: T[i])
			for(int j: b)
				rAdj[j].push_back(i);
	bool nullable[MAX_S] = {false,};
	for(int i = 27; i < M; ++i)
		if(toEps[i]) nullable[i] = true;
	while(true){
		bool renewed = false;
		for(int i = 26; i < M; ++i){
			if(nullable[i]) continue;
			for(auto &b: T[i]){
				if(b.size() == 1){
					if(nullable[b[0]]){
						renewed = nullable[i] = true;
						break;
					}
				}
				else{
					if(nullable[b[0]] && nullable[b[1]]){
						renewed = nullable[i] = true;
						break;
					}
				}
			}
		}
		if(!renewed) break;
	}
	for(int i = 26; i < M; ++i){
		if(T[i].empty()) continue;
		for(int j = T[i].size()-1; j >= 0; --j){
			int s1 = T[i][j][0];
			if(T[i][j].size() == 1){
				if(nullable[s1]) toEps[i] = true;
			}
			else{ // must be 2
				int s2 = T[i][j][1];
				if(nullable[s1] && nullable[s2]){
					toEps[i] = true;
					T[i].push_back(vector<int>(1, s1));
					T[i].push_back(vector<int>(1, s2));
				}
				else if(nullable[s1])
					T[i].push_back(vector<int>(1, s2));
				else if(nullable[s2])
					T[i].push_back(vector<int>(1, s1));
			}
		}
	}
	fill(toEps, toEps+26, false);
	fill(toEps+27, toEps+M, false);

	// UNIT: Eliminate unit rules
	for(int i = 26; i < M; ++i){
		if(T[i].empty()) continue;
		vector<vector<int>> newBranches;
		for(int j = T[i].size()-1; j >= 0; --j){
			vector<int> &b = T[i][j];
			if(b.size() == 2 || b[0] < 26) continue;

			// must be 1
			queue<int> Q;
			bool visited[MAX_S] = {false,};
			Q.push(b[0]);
			visited[i] = visited[b[0]] = true;
			while(!Q.empty()){
				int curr = Q.front(); Q.pop();
				for(auto &nb: T[curr]){
					if(nb.size() == 1 && nb[0] >= 26 && !visited[nb[0]]){
						visited[nb[0]] = true;
						Q.push(nb[0]);
					}
					// must be 2
					else newBranches.push_back(nb);
				}
			}
			T[i].erase(T[i].begin() + j);
		}

		T[i].insert(T[i].end(), newBranches.begin(), newBranches.end());
		sort(T[i].begin(), T[i].end());
		T[i].resize(unique(T[i].begin(), T[i].end()) - T[i].begin());
	}

	while(getline(cin, sentence)){
		string result = "";
		memset(dp, -1, sizeof(dp));
		for(int i = sentence.size(); i > 0; --i){
			for(int j = 0; j+i <= sentence.size(); ++j){
				if(CYK(j, j+i, 26)){
					result = sentence.substr(j, i);
					break;
				}
			}
			if(!result.empty()) break;
		}
		if(result.empty()) cout << "NONE\n";
		else cout << result << '\n';
	}
}