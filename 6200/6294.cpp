#include <cstdio>
#include <unordered_set>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

unordered_set<unsigned long long> H;
int map[8][8], r[5], c[5];
bool result;

void dfs(bool flag, int pos){
	unsigned long long temp = 0;
	for(int i=1; i<=4; i++)
		temp += 1ULL << r[i]*8+c[i];
	if(flag){
		if(H.find(temp) != H.end()) result = true;
	}
	else H.insert(temp);

	if(pos == 4) return;

	for(int i=1; i<=4; i++){
		for(int d=0; d<4; d++){
			int nr = r[i]+roff[d], nc = c[i]+coff[d];
			if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;

			if(map[nr][nc] == 0){
				swap(map[r[i]][c[i]], map[nr][nc]);
				r[i] = nr; c[i] = nc;
				dfs(flag, pos+1);
				r[i] -= roff[d]; c[i] -= coff[d];
				swap(map[r[i]][c[i]], map[nr][nc]);
			}
			else{
				nr += roff[d]; nc += coff[d];
				if(nr < 0 || nr >= 8 || nc < 0 || nc >= 8) continue;
				if(map[nr][nc] == 0){
					swap(map[r[i]][c[i]], map[nr][nc]);
					r[i] = nr; c[i] = nc;
					dfs(flag, pos+1);
					r[i] -= roff[d]*2; c[i] -= coff[d]*2;
					swap(map[r[i]][c[i]], map[nr][nc]);
				}
			}
		}
	}
}

int main(){
	for(int i=1; i<=4; i++){
		scanf("%d %d", r+i, c+i);
		map[--r[i]][--c[i]] = i;
	}
	dfs(false, 0);
	for(int i=1; i<=4; i++)
		map[r[i]][c[i]] = 0;
	for(int i=1; i<=4; i++){
		scanf("%d %d", r+i, c+i);
		map[--r[i]][--c[i]] = i;
	}
	dfs(true, 0);
	puts(result ? "YES" : "NO");
}