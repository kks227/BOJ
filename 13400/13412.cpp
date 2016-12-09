#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	bool p[10001];
	fill(p, p+10001, true);
	p[0] = p[1] = false;
	for(int i=4; i<=10000; i+=2)
		p[i] = false;
	vector<int> prime(1, 2);
	for(int i=3; i<=10000; i+=2){
		if(!p[i]) continue;
		prime.push_back(i);
		for(int j=i*i; j<=10000; j+=i*2)
			p[j] = false;
	}

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int N, factor = 0;
		scanf("%d", &N);
		for(int q: prime){
			if(N%q == 0){
				factor++;
				while(N%q == 0) N /= q;
			}
		}
		if(N > 1) factor++;
		printf("%d\n", factor ? 1<<factor-1 : 1);
	}
}