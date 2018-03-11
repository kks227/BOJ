#include <cstdio>
#include <vector>
#include <set>
using namespace std;
const int M = 1000003;

int main(){
	int R, C;
	char T[1000][1001];
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		scanf("%s", T[i]);

	int H[1000][1001] = {0}, p = 1;
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++)
			H[j][i+1] = (H[j][i] + 1LL*p*T[R-i-1][j]) % M;
		p = 2LL*p % M;
	}

	int lo = 0, hi = R;
	while(lo+1 < hi){
		int mid = (lo+hi)/2;
		vector<int> D[M];
		set<int> dup;
		for(int i=0; i<C; i++){
			int h = H[i][mid];
			if(!D[h].empty()) dup.insert(h);
			D[h].push_back(i);
		}
		bool flag = false;
		for(int h: dup){
			for(int i=0; i<D[h].size()-1; i++){
				for(int j=i+1; j<D[h].size(); j++){
					flag = true;
					for(int k=0; k<mid; k++){
						if(T[R-k-1][D[h][i]] != T[R-k-1][D[h][j]]){
							flag = false;
							break;
						}
					}
					if(flag) break;
				}
				if(flag) break;
			}
			if(flag) break;
		}
		(flag ? lo : hi) = mid;
	}
	printf("%d\n", R-hi);
}