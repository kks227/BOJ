#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int R, C, ld[750][750], rd[750][750];
bool map[750][750];

inline bool invalid(int r, int c){
	return (r<0 || r>=R || c<0 || c>=C);
}

int cntLD(int r, int c){
	if(invalid(r, c)) return 0;
	int &ret = ld[r][c];
	if(ret != -1) return ret;
	if(!map[r][c]) return ret = 0;
	return ret = cntLD(r+1, c-1) + 1;
}

int cntRD(int r, int c){
	if(invalid(r, c)) return 0;
	int &ret = rd[r][c];
	if(ret != -1) return ret;
	if(!map[r][c]) return ret = 0;
	return ret = cntRD(r+1, c+1) + 1;
}

int main(){
	scanf("%d %d", &R, &C);
	for(int i=0; i<R; i++)
		for(int j=0; j<C; j++)
			scanf("%1d", &map[i][j]);
	memset(ld, -1, sizeof(ld));
	memset(rd, -1, sizeof(rd));
	
	int result = 0;
	for(int k=min(R+1, C+1)/2; k>0; k--)
		for(int i=0; i+(k-1)*2<R; i++)
			for(int j=0; j+(k-1)*2<C; j++)
				if(cntLD(i, j+k-1)>=k && cntRD(i, j+k-1)>=k && cntLD(i+k-1, j+2*(k-1))>=k && cntRD(i+k-1, j)>=k){
					printf("%d\n", k);
					return 0;
				}
	puts("0");
}