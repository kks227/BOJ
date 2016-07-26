#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1000000;

int main(){
	vector<int> prime;
	bool isP[MAX+1];
	fill(isP, isP+MAX+1, true);
	for(int i=2; i<=MAX; i++){
		if(!isP[i]) continue;
		prime.push_back(i);
		if(1LL*i*i > MAX) continue;
		for(int j=i*i; j<=MAX; j+=i)
			isP[j] = false;
	}
	int pSize = prime.size();

	int N;
	scanf("%d", &N);
	vector<vector<int>> pn(N, vector<int>(pSize, 0));
	vector<int> wn(pSize, 0);
	for(int i=0; i<N; i++){
		int val;
		scanf("%d", &val);
		for(int j=0; j<pSize && val>1; j++){
			while(val%prime[j] == 0){
				pn[i][j]++;
				wn[j]++;
				val /= prime[j];
			}
		}
	}

	int result = 1, cnt = 0;
	for(int i=0; i<pSize; i++){
		int temp = wn[i] / N;
		for(int j=0; j<temp; j++)
			result *= prime[i];
		for(int j=0; j<N; j++)
			if(pn[j][i] < temp) cnt += temp - pn[j][i];
	}
	printf("%d %d\n", result, cnt);
}