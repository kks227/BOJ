#include <cstdio>
#include <algorithm>
using namespace std;

struct Game{
	int n, c, h;
	Game(): Game(0, 1, 0){}
	Game(int i1, int c1, int h1): n(i1), c(c1), h(h1){}
	bool operator <(const Game &O){
		if(1LL*h*O.c != 1LL*c*O.h) return 1LL*h*O.c > 1LL*c*O.h;
		if(c != O.c) return c < O.c;
		return n < O.n;
	}
};

int main(){
	int N, K;
	Game g[1000];
	scanf("%d %d", &N, &K);
	for(int i=0; i<N; i++){
		int n, c, h;
		scanf("%d %d %d", &n, &c, &h);
		g[i] = Game(n, c, h);
	}
	sort(g, g+N);
	for(int i=0; i<K; i++)
		printf("%d\n", g[i].n);
}