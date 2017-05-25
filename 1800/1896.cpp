#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 0, 1, 0};
const int coff[4] = {0, 1, 0, -1};

struct UnionFind{
	int p[225];
	UnionFind(){ fill(p, p+225, -1); }
	int f(int a){
		if(p[a] < 0) return a;
		return p[a] = f(p[a]);
	}
	bool u(int a, int b){
		a = f(a);
		b = f(b);
		if(a == b) return false;
		p[a] += p[b];
		p[b] = a;
		return true;
	}
};

int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		int R, C, map[15][15], sn[15][15], s[225], SN = 0, scnt[225][8] = {0};
		scanf("%d %d", &R, &C);
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				scanf("%1d", &map[i][j]);
				sn[i][j] = -1;
			}
		}
		UnionFind UF;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				int k;
				scanf("%d", &k);
				for(int d=0; d<4; d++){
					if(k%2){
						int ni = i+roff[d], nj = j+coff[d];
						UF.u(i*15+j, ni*15+nj);
					}
					k /= 2;
				}
			}
		}
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				int k = i*15 + j;
				if(UF.f(k) == k){
					s[SN] = -UF.p[k];
					sn[i][j] = SN++;
				}
			}
		}
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				int k = UF.f(i*15+j);
				sn[i][j] = sn[k/15][k%15];
			}
		}

		bool result = true;
		for(int i=0; i<R; i++){
			for(int j=0; j<C; j++){
				int val = map[i][j];
				scnt[sn[i][j]][val-1]++;
				for(int d=0; d<4; d++){
					for(int k=1; k<=val; k++){
						int ni = i+roff[d]*k, nj = j+coff[d]*k;
						if(ni < 0 || ni >= R || nj < 0 || nj >= C) break;
						if(map[ni][nj] == val){
							result = false;
							break;
						}
					}
					if(!result) break;
				}
				if(!result) break;
			}
			if(!result) break;
		}
		if(result){
			for(int i=0; i<SN; i++){
				for(int j=0; j<s[i]; j++){
					if(scnt[i][j] != 1){
						result = false;
						break;
					}
				}
				if(!result) break;
			}
		}
		puts(result ? "valid" : "invalid");
	}
}