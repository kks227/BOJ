#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = sqrt(2*(1e9))+2;
const int MOD = 1000000007;

int main(){
	int T;
	scanf("%d", &T);
	bool np[MAX] = {1, 1,};
	vector<int> p(1, 2);
	for(int i=3; i<MAX; i+=2){
		if(np[i]) continue;
		p.push_back(i);
		for(int j=i*i; j<MAX; j+=2*i)
			np[j] = true;
	}
	for(int t=0; t<T; t++){
		int N, X[1000], result = 1;
		scanf("%d", &N);
		for(int i=0; i<N; i++){
			int x, j = 0;
			scanf("%d", &x);
			X[i] = x;

			vector<int> d, c;
			while(x && j < p.size()){
				if(x % p[j] == 0){
					d.push_back(p[j]);
					c.push_back(0);
					while(x % p[j] == 0){
						c[c.size()-1]++;
						x /= p[j];
					}
				}
				j++;
			}
			if(x > 1){
				d.push_back(x);
				c.push_back(1);
			}

			for(int j=0; j<d.size(); j++){
				long long temp = 1;
				for(int k=0; k<c[j]-1; k++)
					temp = (temp * d[j]) % MOD;
				temp = (temp * (d[j]-1)) % MOD;
				result = 1LL * result * temp % MOD;
			}
		}

		sort(X, X+N);
		for(int i=0; i<N-1; i++){
			if(X[i] == X[i+1]){
				result = 0;
				break;
			}
		}
		printf("%d\n", result);
	}
}