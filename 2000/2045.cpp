#include <cstdio>
#include <algorithm>
using namespace std;

int map[3][3], d;

void dfs(int remain){
	if(remain == 0) return;

	int vcnt, vpos, sum;
	for(int r=0; r<3; r++){
		vcnt = 0, vpos = -1, sum = 0;
		for(int c=0; c<3; c++){
			if(!map[r][c]){
				vcnt++;
				vpos = c;
			}
			else sum += map[r][c];
		}
		if(vcnt == 1){
			map[r][vpos] = d - sum;
			dfs(remain-1);
			return;
		}
	}
	for(int c=0; c<3; c++){
		vcnt = 0, vpos = -1, sum = 0;
		for(int r=0; r<3; r++){
			if(!map[r][c]){
				vcnt++;
				vpos = r;
			}
			else sum += map[r][c];
		}
		if(vcnt == 1){
			map[vpos][c] = d - sum;
			dfs(remain-1);
			return;
		}
	}
	vcnt = 0, vpos = -1, sum = 0;
	for(int r=0; r<3; r++){
		if(!map[r][r]){
			vcnt++;
			vpos = r;
		}
		else sum += map[r][r];
	}
	if(vcnt == 1){
		map[vpos][vpos] = d - sum;
		dfs(remain-1);
		return;
	}
	vcnt = 0, vpos = -1, sum = 0;
	for(int r=0; r<3; r++){
		if(!map[r][2-r]){
			vcnt++;
			vpos = r;
		}
		else sum += map[r][2-r];
	}
	if(vcnt == 1){
		map[vpos][2-vpos] = d - sum;
		dfs(remain-1);
		return;
	}
}

int main(){
	int cnt = 0, vcnt, sum;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			scanf("%d", &map[i][j]);
			if(!map[i][j]) cnt++;
		}
	}
	for(int r=0; r<3; r++){
		vcnt = 0, sum = 0;
		for(int c=0; c<3; c++){
			if(!map[r][c]) vcnt++;
			else sum += map[r][c];
		}
		if(vcnt == 0) d = sum;
	}
	for(int c=0; c<3; c++){
		vcnt = 0, sum = 0;
		for(int r=0; r<3; r++){
			if(!map[r][c]) vcnt++;
			else sum += map[r][c];
		}
		if(vcnt == 0) d = sum;
	}
	vcnt = 0, sum = 0;
	for(int r=0; r<3; r++){
		if(!map[r][r]) vcnt++;
		else sum += map[r][r];
	}
	if(vcnt == 0) d = sum;
	vcnt = 0, sum = 0;
	for(int r=0; r<3; r++){
		if(!map[r][2-r]) vcnt++;
		else sum += map[r][2-r];
	}
	if(vcnt == 0) d = sum;

	if(d > 0) dfs(cnt);
	else{
		int rsum[3] = {0}, wsum = 0;
		for(int r=0; r<3; r++){
			for(int c=0; c<3; c++)
				rsum[r] += map[r][c];
			wsum += rsum[r];
		}
		for(int r=0; r<3; r++)
			for(int c=0; c<3; c++)
				if(!map[r][c]) map[r][c] = wsum/2 - rsum[r];
	}

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++)
			printf("%d ", map[i][j]);
		puts("");
	}
}