#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int N, fact[11] = {1, 1};
long long dp[11][101][101][101];

inline int comb2(int n){
	return fact[n*2] / fact[n] / fact[n];
}

inline int comb3(int n){
	return fact[n*3] / fact[n] / fact[n] / fact[n];
}

long long xmas(int k, vector<int> toy){
	if(k > N) return 1;
	if(toy[0]==0 && toy[1]==0 && toy[2]==0) return 0;
	long long &ret = dp[k][toy[0]][toy[1]][toy[2]];
	if(ret != -1) return ret;

	ret = 0;
	for(int i=0; i<3; i++)
		if(toy[i] >= k){
			toy[i] -= k;
			ret += xmas(k+1, toy);
			toy[i] += k;
		}
	if(k%2 == 0){
		for(int i=0; i<3; i++){
			if(toy[i] < k/2) continue;
			toy[i] -= k/2;
			for(int j=i+1; j<3; j++){
				if(toy[j] < k/2) continue;
				toy[j] -= k/2;
				ret += xmas(k+1, toy) * comb2(k/2);
				toy[j] += k/2;
			}
			toy[i] += k/2;
		}
	}
	if(k%3 == 0){
		bool possible = true;
		for(int i=0; i<3; i++){
			toy[i] -= k/3;
			if(toy[i] < 0) possible = false;
		}
		if(possible) ret += xmas(k+1, toy) * comb3(k/3);
		for(int i=0; i<3; i++)
			toy[i] += k/3;
	}
	return ret;
}

int main(){
	vector<int> param(3);
	scanf("%d %d %d %d", &N, &param[0], &param[1], &param[2]);
	memset(dp, -1, sizeof(dp));
	for(int i=2; i<=10; i++)
		fact[i] = fact[i-1] * i;
	printf("%lld\n", xmas(1, param));
}