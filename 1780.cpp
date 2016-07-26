#include <cstdio>
using namespace std;

int N, arr[2187][2187], result[3];

void divconq(int r, int c, int n){
	if(n == 1) result[arr[r][c]+1]++;
	else{
		int pivot = arr[r][c];
		bool flag = true;
		for(int i=r; i<r+n; i++){
			for(int j=c; j<c+n; j++)
				if(pivot != arr[i][j]){
					flag = false;
					break;
				}
			if(!flag) break;
		}
		if(flag) result[pivot+1]++;
		else{
			int nn = n/3;
			for(int i=0; i<3; i++)
				for(int j=0; j<3; j++)
					divconq(r+i*nn, c+j*nn, nn);
		}
	}
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);
	divconq(0, 0, N);
	for(int i=0; i<3; i++)
		printf("%d\n", result[i]);
}