#include <cstdio>
#include <unordered_map>
using namespace std;

int N, M, dest[12], threshold, resultCnt, resultSol, currHash;
bool ans[12][30], currSol[30];
unordered_map<long long, int> sol;
unordered_map<long long, int> cnt;

void dfs1(int pos){
	if(pos == threshold){
		long long corrCnt = 0;
		bool fail = false;
		for(int i=0; i<N; i++){
			int tempCnt = 0;
			for(int j=0; j<threshold; j++)
				if(ans[i][j] == currSol[j]) tempCnt++;
			if(tempCnt > dest[i] || dest[i]-tempCnt > M-threshold){
				fail = true;
				break;
			}
			corrCnt = corrCnt*16 + tempCnt;
		}
		if(!fail){
			auto iter = cnt.find(corrCnt);
			if(iter == cnt.end()){
				sol[corrCnt] = currHash;
				cnt[corrCnt] = 1;
			}
			else iter->second++;
		}
		return;
	}

	currSol[pos] = false;
	currHash *= 2;
	dfs1(pos+1);
	currSol[pos] = true;
	currHash++;
	dfs1(pos+1);
	currSol[pos] = false;
	currHash /= 2;
}

void dfs2(int pos){
	if(pos == M){
		long long destCnt = 0;
		bool fail = false;
		for(int i=0; i<N; i++){
			int tempCnt = 0;
			for(int j=threshold; j<M; j++)
				if(ans[i][j] == currSol[j]) tempCnt++;
			if(tempCnt > dest[i] || dest[i]-tempCnt > threshold){
				fail = true;
				break;
			}
			destCnt = destCnt*16 + dest[i] - tempCnt;
		}
		if(!fail){
			auto iter = cnt.find(destCnt);
			if(iter != cnt.end()){
				resultSol = (sol[destCnt] << M-threshold) + currHash;
				resultCnt += iter->second;
			}
		}
		return;
	}

	currSol[pos] = false;
	currHash *= 2;
	dfs2(pos+1);
	currSol[pos] = true;
	currHash++;
	dfs2(pos+1);
	currSol[pos] = false;
	currHash /= 2;
}



int main(){
	int T;
	scanf("%d", &T);
	for(int t=0; t<T; t++){
		scanf("%d %d", &N, &M);
		for(int i=0; i<N; i++){
			for(int j=0; j<M; j++)
				scanf("%1d", &ans[i][j]);
			scanf("%d", dest+i);
		}
		threshold = M/2;
		resultCnt = 0;
		dfs1(0);
		dfs2(threshold);
		if(resultCnt == 1){
			for(int i=0; i<M; i++)
				printf("%1d", (resultSol >> M-1-i) % 2);
			puts("");
		}
		else printf("%d solutions\n", resultCnt);

		sol.clear();
		cnt.clear();
	}
}