#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1e6;

int main(){
	int L, N, F1, F2, x[MAX], c[MAX];
	scanf("%d %d %d %d", &L, &N, &F1, &F2);
	for(int i = 0; i < N; ++i)
		scanf("%d %d", x+i, c+i);
	vector<int> path(1, N-1);
	for(int i = N-2; i >= 0; --i)
		if(c[i] > c[path.back()]) path.push_back(i);
	reverse(path.begin(), path.end());

	long long result = 0, t = 0;
	int pos = 0;
	for(int i: path){
		long long d = x[i] - pos;
		result += d * (F1-F2) * c[i];
		t += d * F1;
		pos = x[i];
	}
	printf("%lld\n", result);
}