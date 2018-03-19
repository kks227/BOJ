#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int N, K = 0, D = -1, cnt[200000] = {0};
	bool accepted[200000] = {false};
	cin >> N;
	unordered_map<string, int> id;
	for(int i=0; i<N; i++){
		int sid, r, m, t, l, L, u;
		string uid;
		cin >> sid >> uid >> r >> m >> t >> l >> L;
		if(id.find(uid) == id.end()){
			u = id[uid] = K++;
			if(uid == "megalusion") D = u;
		}
		else u = id[uid];
		if(accepted[u]) continue;
		else{
			cnt[u]++;
			if(r == 4) accepted[u] = true;
		}
	}
	int p = 0, q = 0;
	for(int i=0; i<K; i++){
		if(i != D && accepted[i]){
			p++;
			q += cnt[i];
		}
	}
	cout << fixed;
	cout.precision(10);
	if(p == 0) cout << 0 << endl;
	else cout << 100.0*p/q << endl;
}