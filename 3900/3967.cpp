#include <cstdio>
using namespace std;

bool used[13];
int val[12], cnt[6], sum[6], cn[12][2] = {
	0, 1, 3, 4, 0, 3, 1, 3, 3, 5, 0, 4,
	1, 5, 0, 2, 2, 4, 2, 5, 1, 2, 4, 5
};
int r[12] = {0, 1, 1, 1, 1, 2, 2, 3, 3, 3, 3, 4};
int c[12] = {4, 1, 3, 5, 7, 2, 6, 1, 3, 5, 7, 4};
char map[5][9];

bool backtrack(int pos){
	if(pos == 12){
		for(int i=0; i<12; i++)
			map[r[i]][c[i]] = val[i]-1+'A';
		return true;
	}
	if(val[pos] > 0) return backtrack(pos+1);

	for(int i=1; i<=12; i++){
		if(used[i]) continue;

		bool flag = true;
		for(int j=0; j<2; j++){
			int temp = cn[pos][j];
			if(sum[temp]+i > 26 || cnt[temp] == 3 && sum[temp]+i != 26) flag = false;
		}
		if(!flag) continue;

		used[i] = true;
		val[pos] = i;
		for(int j=0; j<2; j++){
			int temp = cn[pos][j];
			sum[temp] += i;
			cnt[temp]++;
		}
		if(backtrack(pos+1)) return true;
		used[i] = false;
		val[pos] = 0;
		for(int j=0; j<2; j++){
			int temp = cn[pos][j];
			sum[temp] -= i;
			cnt[temp]--;
		}
	}
	return false;
}

int main(){
	for(int i=0, k=0; i<5; i++){
		for(int j=0; j<9; j++){
			map[i][j] = getchar();
			if(map[i][j] != '.'){
				if(map[i][j] != 'x'){
					val[k] = map[i][j]-'A'+1;
					used[val[k]] = true;
					for(int l=0; l<2; l++){
						int temp = cn[k][l];
						sum[temp] += val[k];
						cnt[temp]++;
					}
				}
				k++;
			}
		}
		getchar();
	}
	backtrack(0);
	for(int i=0, k=0; i<5; i++){
		for(int j=0; j<9; j++)
			putchar(map[i][j]);
		puts("");
	}
}