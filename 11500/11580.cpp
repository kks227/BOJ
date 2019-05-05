#include <cstdio>
#include <set>
#include <map>
#include <utility>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};
typedef pair<int, int> P;

int main(){
	int N, x = 0, y = 0;
	scanf("%d\n", &N);
	set<P> S;
	S.insert(P(0, 0));
	map<char, int> C2D;
	C2D['S'] = 1; C2D['N'] = 0; C2D['E'] = 3; C2D['W'] = 2;
	for(int i = 0; i < N; ++i){
		int d = C2D[getchar()];
		x += coff[d];
		y += roff[d];
		S.insert(P(x, y));
	}
	printf("%d\n", S.size());
}