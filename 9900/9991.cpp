#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<string, int> P;

int main(){
	int N, Q;
	vector<P> p;
	cin >> N >> Q;
	for(int i = 0; i < N; ++i){
		string S;
		cin >> S;
		p.push_back(P(S, i+1));
	}
	sort(p.begin(), p.end());
	for(int i = 0; i < Q; ++i){
		int k;
		string S;
		cin >> k >> S;
		int s = lower_bound(p.begin(), p.end(), P(S, -1)) - p.begin();
		S.push_back(127);
		int e = lower_bound(p.begin(), p.end(), P(S, -1)) - p.begin();
		if(e-s < k) cout << "-1\n";
		else cout << p[s+k-1].second << "\n";
	}
}