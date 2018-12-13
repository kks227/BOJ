#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int MAX = 5000001;

int main(){
	int go[MAX];
	fill(go, go+MAX, -1);
	bool np[MAX] = {true, true,};
	for(int i = 1; i <= MAX/2; ++i)
		if(go[i*2] < 0) go[i*2] = i;
	for(int i = 3; i <= MAX; i += 2){
		if(np[i]) continue;
		for(int j = i*2; j <= MAX; j += i){
			if(go[j] < 0) go[j] = j/i;
			np[j] = true;
		}
	}

	int N;
	scanf("%d", &N);
	for(int i = 0; i < N; ++i){
		int k;
		scanf("%d", &k);
		multiset<int> S;
		while(go[k] >= 0){
			S.insert(k/go[k]);
			k = go[k];
		}
		if(k > 1) S.insert(k);
		for(int v: S)
			printf("%d ", v);
		puts("");
	}
}