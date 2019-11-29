#include <cstdio>
#include <utility>
#include <tuple>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;
const int MAX = 100000;
typedef pair<int, int> IntPair;
typedef tuple<int, int, int> IntTuple;

int main(){
	int N, B, M = 0, D[MAX*2];
	unordered_map<int, int> H;
	set<int> pos;
	multiset<int> diff;
	IntPair cell[MAX];
	IntTuple boots[MAX];
	scanf("%d %d", &N, &B);
	for(int i = 0; i < N; ++i){
		int f;
		scanf("%d", &f);
		if(i > 0 && i < N-1) cell[i-1] = IntPair(f, i);
		D[M++] = f;
	}
	pos.insert(0);
	pos.insert(N-1);
	diff.insert(N-1);
	for(int i = 0; i < B; ++i){
		int s, d;
		scanf("%d %d", &s, &d);
		boots[i] = IntTuple(s, d, i);
		D[M++] = s;
	}
	sort(cell, cell+N-2);
	sort(boots, boots+B);
	sort(D, D+M);
	M = unique(D, D+M) - D;
	for(int i = 0; i < M; ++i)
		H[D[i]] = i;

	bool result[MAX] = {false,};
	for(int i = 0, j = 0, k = 0; i < M; ++i){
		for(; j < N && H[cell[j].first] == i; ++j){
			int x = cell[j].second;
			auto iter = pos.lower_bound(x);
			int b = *iter;
			--iter;
			int a = *iter, d0 = b-a, d1 = x-a, d2 = b-x;
			diff.erase(diff.find(d0));
			diff.insert(d1);
			diff.insert(d2);
			pos.insert(x);
		}
		int y = *diff.rbegin();
		for(; k < B && H[get<0>(boots[k])] == i; ++k)
			result[get<2>(boots[k])] = (get<1>(boots[k]) >= y);
	}
	for(int i = 0; i < B; ++i)
		printf("%d\n", result[i]);
}