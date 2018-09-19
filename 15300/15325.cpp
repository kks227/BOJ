#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int N, threshold, height[40], gold[40];
vector<long long> li1[20], li2[20];
long long currGold;

void dfs1(int pos, int rightest){
	if(pos == threshold){
		if(rightest != -1) li1[rightest].push_back(currGold);
		return;
	}

	dfs1(pos+1, rightest);
	if(rightest == -1 || height[rightest] <= height[pos]){
		currGold += gold[pos];
		dfs1(pos+1, pos);
		currGold -= gold[pos];
	}
}

void dfs2(int pos, int leftest){
	if(pos == threshold-1){
		if(leftest != -1) li2[leftest-threshold].push_back(currGold);
		return;
	}

	dfs2(pos-1, leftest);
	if(leftest == -1 || height[leftest] >= height[pos]){
		currGold += gold[pos];
		dfs2(pos-1, pos);
		currGold -= gold[pos];
	}
}



int main(){
	long long K;
	scanf("%d %lld", &N, &K);
	for(int i=0; i<N; i++)
		scanf("%d %d", height+i, gold+i);
	threshold = N/2;
	dfs1(0, -1);
	dfs2(N-1, -1);
	for(int i=0; i<threshold; i++)
		sort(li1[i].begin(), li1[i].end());
	for(int i=0; i<N-threshold; i++)
		sort(li2[i].begin(), li2[i].end());

	long long result = 0;
	for(int i=0; i<threshold; i++){
		for(int j=0; j<N-threshold; j++){
			if(height[i] > height[j+threshold]) continue;

			int p = 0, q = li2[j].size() - 1;
			for(; p < li1[i].size(); p++){
				while(q > 0 && li1[i][p] + li2[j][q-1] >= K) q--;
				if(li1[i][p] + li2[j][q] >= K) result += li2[j].size() - q;
			}
		}
		result += li1[i].end() - lower_bound(li1[i].begin(), li1[i].end(), K);
	}
	for(int i=0; i<N-threshold; i++)
		result += li2[i].end() - lower_bound(li2[i].begin(), li2[i].end(), K);
	printf("%lld\n", result);
}