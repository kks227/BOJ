#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int N;
vector<int> f, dp1, dp2;

int fc1(int n){
	int &ret = dp1[n];
	if(ret != -1) return ret;
	if(n == 1) return ret = INF;
	if(n == 2) return ret = 1;
	if(n == 3) return ret = 2;

	ret = INF;
	for(int i=1; i<f.size() && f[i]<=n; i++)
		ret = min(fc1(n-f[i]) + f[i-1], ret);
	return ret;
}

int fc2(int n){
	int &ret = dp2[n];
	if(ret != -1) return ret;
	if(n == 1) return ret = -INF;
	if(n == 2) return ret = 1;
	if(n == 3) return ret = 2;

	ret = -INF;
	for(int i=1; i<f.size() && f[i]<=n; i++)
		ret = max(fc2(n-f[i]) + f[i-1], ret);
	return ret;
}

int main(){
	scanf("%d", &N);
	f.push_back(1); f.push_back(2);
	while(1){
		int nf = f[f.size()-2] + f[f.size()-1];
		if(nf > N) break;
		f.push_back(nf);
	}
	dp1 = vector<int>(N+1, -1);
	dp2 = vector<int>(N+1, -1);
	printf("%d %d\n", fc1(N), fc2(N));
}