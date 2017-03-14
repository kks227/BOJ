#include <cstdio>
#include <cmath>
#include <set>
#include <algorithm>
using namespace std;

int N, M, cnt[2], V[2][12];
long long L, d[14][14];

bool partition(int pos=1){
	if(pos == N){
		if(abs(cnt[0]-cnt[1]) > 1) return false;

		int order[12];
		set<long long> S;

		for(int i=0; i<cnt[0]; i++)
			order[i] = i;
		do{
			int *v = V[0];
			long long dist = d[0][v[order[0]]] + d[v[order[cnt[0]-1]]][M];
			for(int i=0; i<cnt[0]-1; i++)
				dist += d[v[order[i]]][v[order[i+1]]];
			S.insert(dist);
		}while(next_permutation(order, order+cnt[0]));

		for(int i=0; i<cnt[1]; i++)
			order[i] = i;
		do{
			int *v = V[1];
			long long dist = d[0][v[order[0]]] + d[v[order[cnt[1]-1]]][M];
			for(int i=0; i<cnt[1]-1; i++)
				dist += d[v[order[i]]][v[order[i+1]]];
			if(S.find(L-dist) != S.end()) return true;
		}while(next_permutation(order, order+cnt[1]));

		return false;
	}
	if(pos == M) return partition(pos+1);

	V[0][cnt[0]++] = pos;
	if(partition(pos+1)) return true;
	cnt[0]--;
	if(cnt[0] > 0){
		V[1][cnt[1]++] = pos;
		if(partition(pos+1)) return true;
		cnt[1]--;
	}
	return false;
}



int main(){
	scanf("%d %lld", &N, &L);
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			scanf("%lld", &d[i][j]);
	if(N == 2){
		printf("%spossible\n", (d[0][1]*2 == L) ? "" : "im");
		return 0;
	}

	bool result = false;
	for(M=1; M<N; M++)
		if(result = partition()) break;
	printf("%spossible\n", result ? "" : "im");
}