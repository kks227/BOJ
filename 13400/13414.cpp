#include <cstdio>
#include <map>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int K, L, N = 0;
	map<int, int> M;
	scanf("%d %d", &K, &L);
	for(int i=0; i<L; i++){
		int val;
		scanf("%d", &val);
		M[val] = i;
	}
	P p[500000];
	for(auto &m: M)
		p[N++] = P(m.second, m.first);
	sort(p, p+N);
	for(int i=0; i<min(K, N); i++)
		printf("%08d\n", p[i].second);
}