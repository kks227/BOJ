#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int Q, r[4], f[4];
	for(int i=0; i<4; i++) cin >> r[i];
	for(int i=0; i<4; i++) cin >> f[i];
	cin >> Q;
	const char* typeName[] = {
		"None",
		"New Customer", "Promising", "About to Sleep", "Hibernating", "Lost",
		"Potential Loyalist", "Need Attention", "About to Leave",
		"Champion", "Loyal Customer", "Can't Lose Them"
	};
	const int nmap[5][5] = {
		{1, 2, 3, 5, 5},
		{6, 6, 3, 4, 5},
		{6, 6, 7, 8, 8},
		{10, 10, 10, 8, 8},
		{9, 10, 10, 8, 11}
	};

	unordered_map<string, int> S2N;
	int recent[100000] = {0}, cnt[100000] = {0}, N = 0;
	for(int q=0; q<Q; q++){
		int o, id;
		string name;
		cin >> o >> name;
		if(S2N.find(name) == S2N.end()) id = S2N[name] = N++;
		else id = S2N[name];

		if(o == 1){
			cnt[id]++;
			recent[id] = q;
		}
		else{
			int type = 0;
			if(cnt[id] != 0){
				int rpos = 0, fpos = 0;
				for(int i=0; i<4; i++){
					if(q-recent[id] > r[i]) rpos++;
					else break;
				}
				for(int i=0; i<4; i++){
					if(cnt[id] > f[i]) fpos++;
					else break;
				}
				type = nmap[fpos][rpos];
			}
			printf("%s\n", typeName[type]);
		}
	}
}