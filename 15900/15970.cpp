#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int INF = 1e9;

int main(){
	int N;
	vector<int> x[5000];
	scanf("%d", &N);
	for(int i=0; i<N; i++){
		int X, Y;
		scanf("%d %d", &X, &Y);
		x[Y-1].push_back(X);
	}
	long long result = 0;
	for(int i=0; i<N; i++){
		if(x[i].empty()) continue;
		sort(x[i].begin(), x[i].end());
		int S = x[i].size();
		result += x[i][1]-x[i][0] + x[i][S-1]-x[i][S-2];
		for(int j=1; j<S-1; j++)
			result += min(x[i][j]-x[i][j-1], x[i][j+1]-x[i][j]);
	}
	printf("%lld\n", result);
}