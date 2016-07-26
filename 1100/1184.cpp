#include <cstdio>
#include <map>
using namespace std;

int main(){

	int N, arr[50][50], subSum[50][50] = {0};
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%d", &arr[i][j]);
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			subSum[i][j] = arr[i][j];
			if(i>0) subSum[i][j] += subSum[i-1][j];
			if(j>0){
				subSum[i][j] += subSum[i][j-1];
				if(i>0) subSum[i][j] -= subSum[i-1][j-1];
			}
		}
	}

	map<int, long long> interest;
	int temp;
	long long result = 0;
	for(int pi=1; pi<N; pi++){
		for(int pj=1; pj<N; pj++){
			for(int r1=0; r1<pi; r1++){
				for(int c1=0; c1<pj; c1++){
					temp = subSum[pi-1][pj-1];
					if(r1>0) temp -= subSum[r1-1][pj-1];
					if(c1>0){
						temp -= subSum[pi-1][c1-1];
						if(r1>0) temp += subSum[r1-1][c1-1];
					}
					if(interest.count(temp)) interest[temp]++;
					else interest[temp] = 1;
				}
			}
			for(int r1=pi+1; r1<=N; r1++){
				for(int c1=pj+1; c1<=N; c1++){
					temp = subSum[r1-1][c1-1] - subSum[pi-1][c1-1] - subSum[r1-1][pj-1] + subSum[pi-1][pj-1];
					if(interest.count(temp)) result += interest[temp];
				}
			}
			interest.clear();
			
			for(int r1=pi+1; r1<=N; r1++){
				for(int c1=0; c1<pj; c1++){
					temp = subSum[r1-1][pj-1] - subSum[pi-1][pj-1];
					if(c1>0) temp -= subSum[r1-1][c1-1] - subSum[pi-1][c1-1];
					if(interest.count(temp)) interest[temp]++;
					else interest[temp] = 1;
				}
			}
			for(int r1=0; r1<pi; r1++){
				for(int c1=pj+1; c1<=N; c1++){
					temp = subSum[pi-1][c1-1] - subSum[pi-1][pj-1];
					if(r1>0) temp -= subSum[r1-1][c1-1] - subSum[r1-1][pj-1];
					if(interest.count(temp)) result += interest[temp];
				}
			}
			interest.clear();
		}
	}

	printf("%lld\n", result);

	return 0;
}