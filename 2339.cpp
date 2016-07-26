#include <cstdio>
#include <set>
using namespace std;

int N, arr[20][20];

int cutting(int r1, int c1, int r2, int c2, int way){
	if(r1==r2 || c1==c2) return 0;

	int cnt = 0, stein = 0;
	set<int> rp, cp;
	for(int i=r1; i<r2; i++)
		for(int j=c1; j<c2; j++){
			if(arr[i][j] == 2) cnt++;
			else if(arr[i][j] == 1){
				rp.insert(i);
				cp.insert(j);
				stein++;
			}
		}
	if(cnt == 0) return 0;
	if(cnt == 1) return !stein;
	if(stein == 0) return 0;

	int result = 0;
	if(way != 1){
		for(int c: cp){
			bool possible = true;
			for(int i=r1; i<r2; i++)
				if(arr[i][c] == 2){
					possible = false;
					break;
				}
			if(possible)
				result += cutting(r1, c1, r2, c, 1) * cutting(r1, c+1, r2, c2, 1);
		}
	}
	if(way != 2){
		for(int r: rp){
			bool possible = true;
			for(int i=c1; i<c2; i++)
				if(arr[r][i] == 2){
					possible = false;
					break;
				}
			if(possible)
				result += cutting(r1, c1, r, c2, 2) * cutting(r+1, c1, r2, c2, 2);
		}
	}
	return result;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);
	int result = cutting(0, 0, N, N, 0);
	printf("%d\n", result ? result : -1);
}