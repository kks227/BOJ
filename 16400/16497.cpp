#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int, int> P;

int main(){
	int N, K, temp = 0;
	scanf("%d", &N);
	P p[200];
	for(int i = 0; i < N; ++i){
		int s, e;
		scanf("%d %d", &s, &e);
		p[i*2] = P(s, 1);
		p[i*2+1] = P(e, -1);
	}
	scanf("%d", &K);
	sort(p, p+2*N);
	for(int i = 0; i < 2*N; ++i){
		temp += p[i].second;
		if(temp > K){
			puts("0");
			return 0;
		}
	}
	puts("1");
}