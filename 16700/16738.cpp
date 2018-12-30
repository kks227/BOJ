#include <cstdio>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, Q, K = 0, cnt[5000], sp[5000], ep[5000];
	scanf("%d %d", &N, &Q);
	set<P> S;
	S.insert(P(0, N));
	for(int i = 0; i < Q; ++i){
		char op[4];
		int x, y;
		scanf("%s %d %d", op, &x, &y);
		if(op[0] == 'n'){
			bool rejected = true;
			for(auto p: S){
				if(p.second - p.first >= y){
					rejected = false;
					S.erase(p);
					if(p.second - p.first > y)
						S.insert(P(p.first+y, p.second));
					sp[K] = p.first+1;
					ep[K] = p.first+y;
					printf("%d %d\n", sp[K], ep[K]);
					cnt[K++] = x;
					break;
				}
			}
			if(rejected) puts("REJECTED");
		}
		else if(op[0] == 'i'){
			cnt[--x] += y;
		}
		else{
			cnt[--x] -= y;
			if(cnt[x] == 0){
				printf("CLEAN %d %d\n", sp[x], ep[x]);
				int s = sp[x]-1, e = ep[x];
				S.insert(P(s, e));
				auto iter = S.find(P(s, e));
				if(iter != S.begin()){
					auto iter2 = iter;
					--iter2;
					if(iter2->second == s){
						s = iter2->first;
						S.insert(P(s, e));
						S.erase(iter);
						S.erase(iter2);
						iter = S.find(P(iter2->first, e));
					}
				}
				if(iter != S.end()){
					auto iter2 = iter;
					++iter2;
					if(iter2 != S.end() && iter2->first == e){
						S.insert(P(s, iter2->second));
						S.erase(iter);
						S.erase(iter2);
					}
				}
			}
		}
	}
}