#include <cstdio>
#include <utility>
#include <set>
using namespace std;
const int MAX = 100000;
const long long M = 1e9;
const int roff[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int coff[8] = {0, 1, 1, 1, 0, -1, -1, -1};
typedef pair<long long, long long> P;

int main(){
	int N, x = MAX*2, y = MAX*2;
	scanf("%d", &N);
	set<long long> p;
	set<P> l;
	p.insert(x*M + y);
	for(int i = 0; i < N; ++i){
		int d;
		scanf("%1d", &d);
		for(int k = 0; k < 2; ++k){
			int x2 = x + coff[d], y2 = y + roff[d];
			p.insert(x2*M + y2);
			l.insert(P(x*M + y, x2*M + y2));
			l.insert(P(x2*M + y2, x*M + y));
			x = x2; y = y2;
		}
	}
	printf("%d\n", 1-p.size()+l.size()/2);
}