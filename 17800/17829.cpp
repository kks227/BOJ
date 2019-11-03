#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int K;
	scanf("%d", &K);
	vector<vector<int>> M1(K, vector<int>(K));
	for(int i = 0; i < K; ++i)
		for(int j = 0; j < K; ++j)
			scanf("%d", &M1[i][j]);
	while(K > 1){
		K /= 2;
		vector<vector<int>> M2(K, vector<int>(K));
		for(int i = 0; i < K; ++i){
			for(int j = 0; j < K; ++j){
				int val[4] = {M1[i*2][j*2], M1[i*2][j*2+1], M1[i*2+1][j*2], M1[i*2+1][j*2+1]};
				sort(val, val+4);
				M2[i][j] = val[2];
			}
		}
		M1 = M2;
	}
	printf("%d\n", M1[0][0]);
}