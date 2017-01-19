#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int MAX = 32000;
typedef pair<int, int> P;

int main(){
	bool isP[MAX];
	fill(isP, isP+MAX, true);
	isP[0] = isP[1] = false;
	vector<int> p(1, 2);
	for(int i=4; i<MAX; i+=2)
		isP[i] = false;
	for(int i=3; i<MAX; i+=2){
		if(!isP[i]) continue;
		p.push_back(i);
		for(int j=i*i; j<MAX; j+=i*2)
			isP[j] = false;
	}

	while(1){
		int N;
		scanf("%d", &N);
		if(N == 0) break;
		if(N == 1){
			puts("0");
			continue;
		}

		vector<P> f;
		for(int i=0; i<p.size() && N>1; i++){
			int cnt = 0;
			while(N%p[i] == 0){
				cnt++;
				N /= p[i];
			}
			if(cnt > 0) f.push_back(P(p[i], cnt));
		}
		if(N > 1) f.push_back(P(N, 1));

		int result = 1;
		for(auto &k: f){
			int a = k.first, b = 1;
			for(int i=1; i<k.second; i++){
				b = a;
				a = b * k.first;
			}
			result *= a-b;
		}
		printf("%d\n", result);
	}
}