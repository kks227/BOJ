#include <cstdio>
#include <utility>
#include <set>
using namespace std;
typedef pair<int, int> P;

int main(){
	while(1){
		int cnt = 0, result = 0, x = 0, y = 0;
		set<P> S;
		S.insert(P(0, 0));
		for(char c; (c = getchar()) != 'Q'; cnt++){
			switch(c){
				case 'U': y++; break;
				case 'D': y--; break;
				case 'L': x--; break;
				case 'R': x++;
			}
			if(S.find(P(x, y)) != S.end()) result++;
			else S.insert(P(x, y));
		}
		getchar();
		if(cnt == 0) break;
		printf("%d\n", result);
	}
}