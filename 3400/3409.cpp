#include <iostream>
#include <string>
#include <unordered_map>
#include <cstring>
#include <cctype>
using namespace std;
const int MAX = 500;

unordered_map<string, int> S2I;
int child[MAX][2], pos, dp[MAX][2001];
string leaf[MAX], E;

int consume(int curr, int pos){
	int &ret = dp[curr][pos];
	if(ret != -1) return ret;
	if(pos == E.size()) return ret = 0;

	ret = 0;
	if(child[curr][0] < 0){
		for(int i = 0, j = 0; i < leaf[curr].size() && pos+j < E.size(); ++i){
			if(leaf[curr][i] == E[pos+j]){
				++j;
				++ret;
			}
		}
		return ret;
	}
	int temp = consume(child[curr][0], pos);
	return ret = consume(child[curr][1], pos+temp) + temp;
}

int main(){
	int T;
	cin >> T;
	for(int t = 0; t < T; ++t){
		int N, M = 0;
		cin >> N;
		S2I.clear();
		for(int i = 0; i < N; ++i){
			string var, dummy, A;
			cin >> var >> dummy >> A;
			if(S2I.find(var) == S2I.end()) S2I[var] = M++;
			int u = S2I[var];
			if(isupper(A[0])){
				string B;
				cin >> dummy >> B;
				if(S2I.find(A) == S2I.end()) S2I[A] = M++;
				int v = S2I[A];
				if(S2I.find(B) == S2I.end()) S2I[B] = M++;
				int w = S2I[B];
				child[u][0] = v;
				child[u][1] = w;
				leaf[u] = "";
			}
			else{
				child[u][0] = child[u][1] = -1;
				leaf[u] = A;
			}
		}
		string S;
		cin >> S >> E;
		memset(dp, -1, sizeof(dp));
		cout << (consume(S2I[S], 0) == E.size() ? "YES" : "NO") << '\n';
	}
}