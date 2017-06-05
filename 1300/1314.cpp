#include <cstdio>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <functional>
using namespace std;
const long long INF = 1e18;
const int D = 1<<13;
typedef pair<int, int> P;

int N, w[13], t[13];
long long B, dist[2][D];
int wSum, tMax, curr, bitmask, side, n;
bool b[13][13], visited[2][D] = {0}, possible[D];
priority_queue<P, vector<P>, greater<P>> PQ;

void constructPArr(){
	if(n == N){
		int cnt = 0;
		bool flag = true;
		for(int i=0; i<N; i++){
			if(bitmask & 1<<i){
				cnt++;
				if(!flag) continue;

				bool believe = false;
				for(int j=0; j<N; j++){
					if(i != j && bitmask & 1<<j && b[i][j]){
						believe = true;
						break;
					}
				}
				if(!believe) flag = false;
			}
		}
		possible[bitmask] = (cnt == 1 || cnt > 1 && flag);
		return;
	}

	n++;
	constructPArr();
	wSum += w[n-1];
	bitmask += (1<<n-1);
	constructPArr();
	wSum -= w[n-1];
	bitmask -= (1<<n-1);
	n--;
}

void pushPQ(){
	if(n == N){
		if(!possible[bitmask]) return;

		int next = bitmask | (1<<N)-1 & ~curr;
		if(dist[!side][next] > dist[side][curr] + tMax){
			dist[!side][next] = dist[side][curr] + tMax;
			PQ.push({dist[!side][next], D*(!side) + next});
		}
		return;
	}

	n++;
	pushPQ();
	if((curr & 1<<n-1) && wSum + w[n-1] <= B){
		int tMax0 = tMax;
		tMax = max(tMax, t[n-1]);
		wSum += w[n-1];
		bitmask += (1<<n-1);
		pushPQ();
		wSum -= w[n-1];
		bitmask -= (1<<n-1);
		tMax = tMax0;
	}
	n--;
}

int main(){
	scanf("%d", &N);
	for(int i=0; i<N; i++)
		scanf("%d %d", w+i, t+i);
	for(int i=0; i<N; i++){
		getchar();
		for(int j=0; j<N; j++)
			b[i][j] = (getchar() == 'Y');
	}
	scanf("%lld", &B);
	for(int i=0; i<N; i++){
		if(w[i] > B){
			puts("-1");
			return 0;
		}
	}

	constructPArr();
	for(int i=0; i<2; i++)
		fill(dist[i], dist[i]+D, INF);
	curr = (1<<N) - 1;
	dist[0][curr] = 0;
	pushPQ();
	while(!PQ.empty()){
		do{
			curr = PQ.top().second % D;
			side = PQ.top().second / D;
			PQ.pop();
		}while(visited[side][curr] && !PQ.empty());
		if(visited[side][curr]) break;
		visited[side][curr] = true;
		if(side && curr == (1<<N)-1) break;
		pushPQ();
	}
	printf("%lld\n", dist[1][(1<<N)-1] < INF ? dist[1][(1<<N)-1] : -1);
}