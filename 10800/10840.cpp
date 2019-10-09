#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 1500;

int main(){
	char S[MAX+1], T[MAX+1];
	scanf("%s %s", S, T);
	int M = strlen(S), N = strlen(T), result = 0;
	for(int k = min(M, N); k > 0; --k){
		vector<int> cnt(26);
		set<vector<int>> vSet;

		for(int i = 0; i < k; ++i)
			++cnt[S[i]-'a'];
		vSet.insert(cnt);
		for(int i = k; i < M; ++i){
			++cnt[S[i]-'a'];
			--cnt[S[i-k]-'a'];
			vSet.insert(cnt);
		}

		bool flag = false;
		fill(cnt.begin(), cnt.end(), 0);
		for(int i = 0; i < k; ++i)
			++cnt[T[i]-'a'];
		if(vSet.find(cnt) != vSet.end()) flag = true;
		for(int i = k; !flag && i < N; ++i){
			++cnt[T[i]-'a'];
			--cnt[T[i-k]-'a'];
			if(vSet.find(cnt) != vSet.end()) flag = true;
		}
		if(flag){
			result = k;
			break;
		}
	}
	printf("%d\n", result);
}